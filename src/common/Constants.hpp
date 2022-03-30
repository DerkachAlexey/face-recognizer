#ifndef COMMON_CONSTANTS
#define COMMON_CONSTANTS

#include <string>

namespace fr {

namespace common {

namespace constants {

inline const std::string applicationName{"FaceRecognizer"};

// logs constants
inline const std::string logDirectoryName{"logs"};
inline const std::string logFileName{"FaceRecognition.log"};
inline const std::string logPattern{
    "[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v"};
} // namespace constants
} // namespace common
} // namespace fr
#endif
