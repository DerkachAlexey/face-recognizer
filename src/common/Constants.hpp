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

// logs constants
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
