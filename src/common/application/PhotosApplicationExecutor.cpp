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
    std::filesystem::current_path(common::constants::homeDir);
    std::filesystem::current_path(common::constants::configFolder);
    std::filesystem::current_path(common::constants::projectFolder);
    std::filesystem::current_path(common::constants::sourcePhotosFolder);

    cvDom::FrameSourcesReceiver frameReceiver(
        std::filesystem::current_path().string());
    cv::CascadeClassifier faceCascade;

    //TODO: awful approach of loading file. Use fylesystem and relative paths
    // to load the file
    faceCascade.load("/usr/local/share/data/haarcascades/"
                     "haarcascade_frontalface_alt.xml");

    std::filesystem::current_path(common::constants::homeDir);

    while (!frameReceiver.isEmpty()) {
        cv::Mat frame;
        frameReceiver >> frame;

        if (frame.empty())
        {
            m_logger.warn("execute, obtained frame is empty");
        }

        //TODO: implement face position detection, face recognition

        std::vector<cv::Rect> faces;

        faceCascade.detectMultiScale(frame, faces, 1.1, 3, 0, cv::Size(20, 20));

        // TEMP CODE TO SHOW DETECTION RESULTS
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], cv::Scalar(255, 255, 255), 1, 1, 0);
        }

        cv::namedWindow("Face", cv::WINDOW_NORMAL);
        cv::imshow("Face", frame);

        int k = cv::waitKey(0);
    }
}

} // namespace fr
} // namespace common
