#include "CameraFramesReceiver.hpp"
#include "ServicesLocator.hpp"
#include "EnumNamesProvider.hpp"

namespace fr
{

namespace cvDom
{

CameraFramesReceiver::CameraFramesReceiver(enums::CameraType cameraType):
    m_capture(static_cast<int>(cameraType))
{
    if (!m_capture.isOpened())
    {
        auto enumsProvider =
            services::ServicesLocator::getService<services::EnumNamesProvider>();

        auto cameraTypeView = enumsProvider->getName(cameraType);
        m_logger.error("constructor, cannot open: " + cameraTypeView);
    }
}

IFrameReceiver &CameraFramesReceiver::operator>>(cv::Mat &outMat)
{
    if (!isEmpty())
    {
        m_capture >> outMat;
    }
    else
    {
        m_logger.warn("operator >>, cap is closed");
    }

    return *this;
}

bool CameraFramesReceiver::isEmpty() const
{
    return !m_capture.isOpened();
}

} // namespace cvDom
} // namespace fr


