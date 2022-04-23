#ifndef CV_CAMERAFRAMESRECEIVER_H
#define CV_CAMERAFRAMESRECEIVER_H

#include "IFrameReceiver.hpp"
#include "Enums.hpp"
#include "Logger.hpp"
#include <opencv2/opencv.hpp>


namespace cv
{
class Mat;
}

namespace fr
{

namespace cvDom
{

// FrameReceiver is dedicated to retrieve frames from
// videos/folders with folders, etc.
class CameraFramesReceiver : public IFrameReceiver
{
public:
    CameraFramesReceiver(enums::CameraType cameraType);

    IFrameReceiver& operator>>(cv::Mat& outMat) override;
    bool isEmpty() const;

private:
    cv::VideoCapture m_capture;
    common::Logger m_logger{"fr.cvDom.CameraFramesReceiver"};
};

} // namespace cvDom
} // namespace fr

#endif // CV_FRAMESOURCESRECEIVER_H

