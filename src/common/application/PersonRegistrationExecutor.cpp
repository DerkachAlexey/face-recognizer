#include "common/application/PersonRegistrationExecutor.hpp"
#include "common/Constants.hpp"
#include "cvDomain/Constants.hpp"
#include "services/ServicesLocator.hpp"
#include "services/DBManager.hpp"
#include "services/PathProvider.hpp"
#include "services/EnumNamesProvider.hpp"
#include "services/ArgsInterpreter.hpp"

#include <filesystem>

namespace fr
{

namespace common
{

PersonRegistrationExecutor::PersonRegistrationExecutor():
      m_frameReceiver(cvDom::enums::CameraType::WEB_CAMERA)
{
    configureAlgorithms();
}

void PersonRegistrationExecutor::execute()
{
    m_isRunning = true;
    while (m_isRunning && !m_frameReceiver.isEmpty())
    {
        cv::Mat frame;
        m_frameReceiver >> frame;

        if (frame.empty())
        {
            m_logger.warn("execute, obtained frame is empty");
        }

        std::vector<cv::Rect> faces;

        m_haarCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], cv::Scalar(255, 255, 255), 1, 1, 0);
        }

        cv::imshow("registration", frame);

        processKeyPress(cv::waitKey(10), frame, faces);
    }
}

void PersonRegistrationExecutor::configureAlgorithms()
{
    m_haarCascade.load(cvDom::constants::haarCascadesPath);
}

void PersonRegistrationExecutor::processKeyPress(
    int key, cv::Mat& photo, std::vector<cv::Rect>& faces)
{
    if (static_cast<char>(key) == 's')
    {
        saveFaceToDB(photo, faces);
    }
    else if (key == 27) // ESC
    {
        m_isRunning = false;
    }
}

void PersonRegistrationExecutor::saveFaceToDB(
    cv::Mat &faceFrame, std::vector<cv::Rect>& faces)
{
    // We should register only one face in image
    if (faces.size() > 1)
    {
        m_logger.warn("saveFaceToDB, there are more than one faces");
        return;
    }

    if (faces.size() < 1)
    {
        m_logger.warn("saveFaceToDB, there is no face in image");
        return;
    }

    auto& faceRect = faces.front();
    cv::Mat grayFrame;
    cv::cvtColor(faceFrame, grayFrame, cv::COLOR_BGR2GRAY);

    auto face = grayFrame(faceRect);
    cv::resize(face, face,
               {cvDom::constants::defaultPhotoHeight, cvDom::constants::defaultPhotoWidth});

    auto pathProvider =
        services::ServicesLocator::getService<services::PathProvider>();
    auto dbManager =
        services::ServicesLocator::getService<services::db::DBManager>();
    auto enumNamesProvider =
        services::ServicesLocator::getService<services::EnumNamesProvider>();
    auto argsInterpreter = services::ServicesLocator::getService<
        services::ArgumentsInterpreter>();

    const std::string& name = argsInterpreter->getNameToRegister();

    const auto pathToSvedPhoto =
        pathProvider->getPath(services::enums::Path::PHOTOS_BASE)
        + std::filesystem::path::preferred_separator
        + name
        + constants::filesExtensionSeparator
        + enumNamesProvider->getName(enums::Extensions::JPG);

    cv::imwrite(pathToSvedPhoto, face);

    if (dbManager->write(name, pathToSvedPhoto))
    {
        m_logger.info("Face successfully registered. Welcome " + name);
        return;
    }
}

} // namespace fr
} // namespace common
