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
    preprocessUserDatabaseFolder();
}

void PersonRegistrationExecutor::execute()
{
    auto argsInterpreter = services::ServicesLocator::getService<
        services::ArgumentsInterpreter>();
    auto dbManager =
        services::ServicesLocator::getService<services::db::DBManager>();
    auto pathProvider =
        services::ServicesLocator::getService<services::PathProvider>();

    const std::string& name = argsInterpreter->getNameToRegister();

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

    if (dbManager->write(name, pathProvider->getUserBasePath(name)))
    {
        m_logger.info("Person successfully registered. Welcome " + name);
    }
    else
    {
        m_logger.error("Person was not registered. See logs");
    }
}

void PersonRegistrationExecutor::configureAlgorithms()
{
    m_haarCascade.load(cvDom::constants::haarCascadesPath);
}

void PersonRegistrationExecutor::preprocessUserDatabaseFolder()
{
    auto pathProvider =
        services::ServicesLocator::getService<services::PathProvider>();
    auto argsInterpreter = services::ServicesLocator::getService<
        services::ArgumentsInterpreter>();

    std::filesystem::remove_all(
        pathProvider->getUserBasePath(argsInterpreter->getNameToRegister()));
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

    static int photoNumber = 0;

    auto& faceRect = faces.front();
    cv::Mat processedPhoto = processPhoto(faceFrame, faceRect);

    auto pathProvider =
        services::ServicesLocator::getService<services::PathProvider>();
    auto enumNamesProvider =
        services::ServicesLocator::getService<services::EnumNamesProvider>();
    auto argsInterpreter = services::ServicesLocator::getService<
        services::ArgumentsInterpreter>();

    const std::string& name = argsInterpreter->getNameToRegister();

    const auto pathToSvedPhoto =
        pathProvider->getUserBasePath(name)
        + std::filesystem::path::preferred_separator
        + name
        + std::to_string(photoNumber)
        + constants::filesExtensionSeparator
        + enumNamesProvider->getName(enums::Extensions::JPG);

    cv::imwrite(pathToSvedPhoto, processedPhoto);

    m_logger.info("Photo " + pathToSvedPhoto +" successfully saved");
    ++photoNumber;
}

cv::Mat PersonRegistrationExecutor::processPhoto(
    const cv::Mat &photoToProcess, const cv::Rect& rectToCrop)
{
    cv::Mat grayFrame;
    cv::cvtColor(photoToProcess, grayFrame, cv::COLOR_BGR2GRAY);

    auto face = grayFrame(rectToCrop);
    cv::resize(face, face,
               {cvDom::constants::defaultPhotoHeight, cvDom::constants::defaultPhotoWidth});

    return face;
}

} // namespace fr
} // namespace common
