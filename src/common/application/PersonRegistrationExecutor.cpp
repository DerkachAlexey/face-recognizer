#include "PersonRegistrationExecutor.hpp"
#include "Constants.hpp"
#include "cvDomain/Constants.hpp"

#include <filesystem>

//TEMP INCLUDES
#include <iostream>

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
    while (!m_frameReceiver.isEmpty()) {

        cv::Mat frame;
        m_frameReceiver >> frame;

        if (frame.empty())
        {
            m_logger.warn("execute, obtained frame is empty");
        }

        std::vector<cv::Rect> faces;

        m_haarCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));

        // CODE TO SHOW DETECTION RESULTS
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], cv::Scalar(255, 255, 255), 1, 1, 0);
        }

        cv::imshow("Face", frame);

        processKeyPress(cv::waitKey(25));
    }
}

void PersonRegistrationExecutor::configureAlgorithms()
{
    std::filesystem::current_path(common::constants::homeDir);
    std::filesystem::current_path(common::constants::configFolder);
    std::filesystem::current_path(common::constants::projectFolder);
    std::filesystem::current_path(common::constants::photosDatabaseFolder);

    m_haarCascade = cv::CascadeClassifier();

    m_haarCascade.load(cvDom::constants::haarCascadesPath);

    std::filesystem::current_path(common::constants::homeDir);
}

void PersonRegistrationExecutor::processKeyPress(int key)
{
    switch
}

} // namespace fr
} // namespace common