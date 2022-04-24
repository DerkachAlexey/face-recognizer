#ifndef COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H
#define COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H

#include "IApplicationExecutor.hpp"
#include "Logger.hpp"
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
    void processKeyPress(int key);
    void savePhotoToDB(cv::Mat& faceFrame);

private:
    cv::CascadeClassifier m_haarCascade;
    cvDom::CameraFramesReceiver m_frameReceiver;
    Logger m_logger{"fr.common.application.PhotosApplicationExecutor"};
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PERSONREGISTRATIONEXECUTOR_H
