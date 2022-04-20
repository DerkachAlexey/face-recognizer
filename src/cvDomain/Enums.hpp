#ifndef CV_ENUMS_H
#define CV_ENUMS_H

namespace fr
{

namespace cvDom
{

namespace enums
{

// FrameReceiver is dedicated to retrieve frames from
// videos/folders with folders, etc.
enum class FramesFormats
{
    JPEG = 0,
    PNG = 1
};

enum class SourcesType
{
    FRAMES_FOLDER = 0,
    VIDEO = 1
};

} // namespace enums
} // namespace cvDom
} // namespace fr

#endif // CV_ENUMS_H

