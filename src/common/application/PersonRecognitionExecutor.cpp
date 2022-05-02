#include "common/application/PersonRecognitionExecutor.hpp"
#include "cvDomain/Constants.hpp"
#include "cvDomain/FrameSourcesReceiver.hpp"
#include "services/DBManager.hpp"
#include "services/ServicesLocator.hpp"

#include <numeric>

namespace fr
{

namespace common
{

PersonRecognitionExecutor::PersonRecognitionExecutor():
      m_framesReceiver(cvDom::enums::CameraType::WEB_CAMERA),
      m_faceRecognizer(cv::face::EigenFaceRecognizer::create())
{
    configureAlgorithms();
}

void PersonRecognitionExecutor::execute()
{
    m_isRunning = true;
    while (m_isRunning && !m_framesReceiver.isEmpty())
    {
        cv::Mat frame;
        m_framesReceiver >> frame;

        if (frame.empty())
        {
            m_logger.warn("execute, obtained frame is empty");
        }

        std::vector<cv::Rect> faces;
        cv::Mat frameToShow;
        frame.copyTo(frameToShow);

        m_faceDetector.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frameToShow, faces[i], cv::Scalar(255, 255, 255), 1, 1, 0);
        }

        cv::imshow("recognition", frameToShow);

        auto processedPhoto = processPhoto(frame, faces);

        if (!processedPhoto)
        {
            continue;
        }

        auto predictedLabel = m_faceRecognizer->predict(*processedPhoto);

        m_logger.info("execute, recognized person: "
                      + m_knownPeople.at(predictedLabel));


        processKeyPress(cv::waitKey(10));
    }
}

void PersonRecognitionExecutor::configureAlgorithms()
{
    m_faceDetector.load(cvDom::constants::haarCascadesPath);

    // should be called in registration mode and saved
    // after new photo appears
    const auto& DBInfo = loadDBPhotos();
    trainFaceRecognizer(DBInfo);
}

void PersonRecognitionExecutor::trainFaceRecognizer(
    const TrainingData& peopleInfo)
{
    m_faceRecognizer->train(peopleInfo.photos, peopleInfo.labels);
}

TrainingData PersonRecognitionExecutor::loadDBPhotos()
{
    std::vector<cv::Mat> databasePhotos;
    std::vector<int> labels;

    auto database =
        services::ServicesLocator::getService<services::db::DBManager>();

    const auto& loadedData = database->loadAllData();
    int personNumber = 0;

    for (const auto& data : loadedData)
    {
        for (auto& dirEntry : std::filesystem::directory_iterator(data.second))
        {
            // We assume that all files are present
            auto dbPhoto = cv::imread(dirEntry.path(), cv::IMREAD_GRAYSCALE);

            databasePhotos.push_back(dbPhoto);
            labels.push_back(personNumber);
        }

        ++personNumber;
        m_knownPeople.push_back(data.first);
    }

    return {databasePhotos, labels};
}

void PersonRecognitionExecutor::processKeyPress(int key)
{
    if (key == 27) // ESC
    {
        m_isRunning = false;
    }
}

std::optional<cv::Mat> PersonRecognitionExecutor::processPhoto(
    const cv::Mat &frame, const std::vector<cv::Rect> &faces)
{
    if (faces.size() > 1 || faces.size() < 1)
    {
        m_logger.warn("processPhoto, "
                      "cannot process photo with more or less than one face");

        return std::nullopt;
    }
    cv::Mat grayFrame;
    cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

    auto croppedPhoto = grayFrame(faces.front());
    cv::Mat resizedPhoto;

    cv::resize(croppedPhoto, resizedPhoto,
        {cvDom::constants::defaultPhotoHeight, cvDom::constants::defaultPhotoWidth});

    return resizedPhoto;
}

} // namespace fr
} // namespace common
