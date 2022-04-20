#ifndef CV_FRAMERECEIVER_H
#define CV_FRAMERECEIVER_H

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
class IFrameReceiver
{
public:
    virtual IFrameReceiver& operator >>(cv::Mat&) = 0;
};

} // namespace cvDom
} // namespace fr

#endif // CV_FRAMERECEIVER_H

