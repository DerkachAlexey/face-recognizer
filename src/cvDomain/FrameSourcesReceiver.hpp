#ifndef CV_FRAMESOURCESRECEIVER_H
#define CV_FRAMESOURCESRECEIVER_H

#include "IFrameReceiver.hpp"
#include <filesystem>
#include <string>

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
class FrameSourcesReceiver : public IFrameReceiver
{
public:
    FrameSourcesReceiver(const std::string& frameSourcesFolder);

    IFrameReceiver& operator>>(cv::Mat& outMat) override;
    bool isEmpty() const;

private:
    std::filesystem::directory_iterator m_sourceDirIt;
    std::filesystem::path m_currentPath;
};

} // namespace cvDom
} // namespace fr

#endif // CV_FRAMESOURCESRECEIVER_H

