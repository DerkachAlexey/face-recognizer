#include "PhotosApplicationExecutor.hpp"
#include "Constants.hpp"
#include "cvDomain/FrameSourcesReceiver.hpp"
#include "cvDomain/Constants.hpp"
#include "services/PathProvider.hpp"
#include "services/ServicesLocator.hpp"

#include <opencv2/opencv.hpp>

//TEMP INCLUDES
#include <iostream>

namespace fr
{

namespace common
{

void PhotosApplicationExecutor::execute()
{
    auto pathProvider =
        services::ServicesLocator::getService<services::PathProvider>();

    cvDom::FrameSourcesReceiver frameReceiver(
        pathProvider->getPath(services::enums::Path::SOURCE_PHOTOS));
    cv::CascadeClassifier faceCascade;

    //TODO: awful approach of loading file. Use fylesystem and relative paths
    // to load the file
    faceCascade.load(cvDom::constants::haarCascadesPath);

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
