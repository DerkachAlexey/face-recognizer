#ifndef COMMON_CONSTANTS
#define COMMON_CONSTANTS

#include <string>

namespace fr
{

namespace common
{

namespace constants
{

inline const std::string applicationName{"face-recognizer"};
inline const std::string filesExtensionSeparator{"."};

// logs constants
inline const std::string logFileName{"FaceRecognition"};
inline const std::string logFileExtension{"log"};
inline const std::string logPattern{
    "[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v"};

// args constants
inline const std::string modeArg{"--mode"};
inline const std::string nameArg{"--name"};

} // namespace constants
} // namespace common
} // namespace fr
#endif
