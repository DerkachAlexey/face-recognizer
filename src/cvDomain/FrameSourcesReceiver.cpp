#include "cvDomain/FrameSourcesReceiver.hpp"
#include "common/Constants.hpp"
#include <opencv2/opencv.hpp>
#include <filesystem>

namespace fr
{

namespace cvDom
{

FrameSourcesReceiver::FrameSourcesReceiver(const std::string &frameSourcesFolder)
{
    m_currentPath = std::filesystem::path(frameSourcesFolder);

    m_sourceDirIt = std::filesystem::directory_iterator{m_currentPath};
}

IFrameReceiver& FrameSourcesReceiver::operator>>(cv::Mat &outMat)
{
    if (m_sourceDirIt != end(m_sourceDirIt))
    {
        outMat = cv::imread(m_sourceDirIt->path().c_str());
        ++m_sourceDirIt;
    }

    return *this;
}

bool FrameSourcesReceiver::isEmpty() const
{
    return m_sourceDirIt == end(m_sourceDirIt);
}



} // namespace cvDom
} // namespace fr


