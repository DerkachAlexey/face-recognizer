#ifndef COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H
#define COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H

#include "common/application/IApplicationExecutor.hpp"
#include "common/Logger.hpp"
#include "cvDomain/CameraFramesReceiver.hpp"

#include <opencv2/opencv.hpp>

namespace fr
{

namespace common
{

class PersonRegistrationExecutor : public IApplicationExecutor
{
public:
    PersonRegistrationExecutor();
    void execute() override;

private:
    void configureAlgorithms();
    void processKeyPress(
        int key, cv::Mat& photo, std::vector<cv::Rect>& faces);
    void saveFaceToDB(cv::Mat& faceFrame, std::vector<cv::Rect>& faces);

private:
    cv::CascadeClassifier m_haarCascade;
    cvDom::CameraFramesReceiver m_frameReceiver;

    Logger m_logger{"fr.common.application.PhotosApplicationExecutor"};

    bool m_isRunning{false};
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H
