#include "PhotosApplicationExecutor.hpp"
#include "Constants.hpp"
#include "FrameSourcesReceiver.hpp"
#include <opencv2/opencv.hpp>

//TEMP INCLUDES
#include <iostream>

namespace fr
{

namespace common
{

void PhotosApplicationExecutor::execute()
{
    //TODO: implement
    cvDom::FrameSourcesReceiver frameReceiver(constants::sourcePhotosFolder);

    while (!frameReceiver.isEmpty())
    {
        cv::Mat frame;
        frameReceiver >> frame;

        if (frame.empty())
        {
            m_logger.warn("execute, obtained frame is empty");
        }

        //TODO: implement face position detection, face recognition

        cv::imshow("Face", frame);
        int k = cv::waitKey(0);
    }
}

} // namespace fr
} // namespace common
