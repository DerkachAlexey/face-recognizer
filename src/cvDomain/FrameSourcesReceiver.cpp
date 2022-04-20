#include "FrameSourcesReceiver.hpp"
#include "Constants.hpp"
#include <opencv2/opencv.hpp>
#include <filesystem>

namespace fr
{

namespace cvDom
{

FrameSourcesReceiver::FrameSourcesReceiver(const std::string &frameSourcesFolder)
{
    const auto curPath = std::filesystem::current_path().string();

    auto photosPathView = curPath +
                        std::filesystem::path::preferred_separator +
                        common::constants::sourcePhotosFolder;

    m_currentPath = std::filesystem::path(photosPathView);

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


