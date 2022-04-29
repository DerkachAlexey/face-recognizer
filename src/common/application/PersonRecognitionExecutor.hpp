#ifndef COMMON_APPLICATION_PERSONRECOGNITIONEXECUTOR_HPP
#define COMMON_APPLICATION_PERSONRECOGNITIONEXECUTOR_HPP

#include "cvDomain/CameraFramesReceiver.hpp"
#include "IApplicationExecutor.hpp"
#include "Logger.hpp"

#include <opencv2/face.hpp>

namespace fr
{

namespace common
{

class PersonRecognitionExecutor : public IApplicationExecutor
{
    using PersonInfo = std::pair<std::string, cv::Mat>;
public:
    PersonRecognitionExecutor();

    void execute() override;

private:
    void configureAlgorithms();
    void trainFaceRecognizer(const std::vector<cv::Mat>& DBPhotos);
    std::vector<cv::Mat> loadDBPhotos();
    void processKeyPress(int key);
    std::optional<cv::Mat> processPhoto(
        const cv::Mat& frame, const std::vector<cv::Rect>& faces);

private:
    cvDom::CameraFramesReceiver m_framesReceiver;
    cv::CascadeClassifier m_faceDetector;
    cv::Ptr<cv::face::EigenFaceRecognizer> m_faceRecognizer;
    std::vector<std::string> m_knownPeople;

    Logger m_logger{"fr.common.application.PersonRecognitionExecutor"};

    bool m_isRunning{false};
};

} // namespace fr
} // namespace common

#endif // COMMON_APPLICATION_PERSONRECOGNITIONEXECUTOR_HPP
