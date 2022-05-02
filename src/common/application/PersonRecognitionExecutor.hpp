#ifndef COMMON_APPLICATION_PERSONRECOGNITIONEXECUTOR_HPP
#define COMMON_APPLICATION_PERSONRECOGNITIONEXECUTOR_HPP

#include "cvDomain/CameraFramesReceiver.hpp"
#include "common/application/IApplicationExecutor.hpp"
#include "common/Logger.hpp"

#include <opencv2/face.hpp>

namespace fr
{

namespace common
{

struct TrainingData
{
    std::vector<cv::Mat> photos;
    std::vector<int> labels;
};

class PersonRecognitionExecutor : public IApplicationExecutor
{
public:
    PersonRecognitionExecutor();

    void execute() override;

private:
    void configureAlgorithms();
    void trainFaceRecognizer(const TrainingData& peopleInfo);
   TrainingData loadDBPhotos();
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
