#ifndef COMMON_CONSTANTS
#define COMMON_CONSTANTS

#include <string>

namespace fr
{

namespace common
{

namespace constants
{

inline const std::string applicationName{"FaceRecognizer"};

// filesystem constants

// TODO: make reusable for different platforms
inline const std::string projectRoot{"FaceRecognition"};

inline const std::string filesExtensionSeparator{"."};
inline const std::string photosDatabaseFolder{"photosDatabase"};
inline const std::string sourcePhotosFolder{"sourcePhotos"};

// logs constants
inline const std::string logDirectoryName{"logs"};
inline const std::string logFileName{"FaceRecognition"};
inline const std::string logFileExtension{"log"};
inline const std::string logPattern{
    "[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v"};

// args constants
inline const std::string modeArg{"--mode"};

} // namespace constants
} // namespace common
} // namespace fr
#endif
