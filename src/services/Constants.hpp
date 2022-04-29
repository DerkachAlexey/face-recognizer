#ifndef SERVICES_CONSTANTS_H
#define SERVICES_CONSTANTS_H

#include <string>

namespace fr
{

namespace services
{

namespace constants
{

inline const std::string dbName{"faceRecDB"};

// filesystem constants

// TODO: make reusable for different platforms
inline const auto homeDir = std::string(std::getenv("HOME"));
inline const std::string configFolder{".config"};
inline const std::string projectFolder{"FaceRecognition"};

inline const std::string photosDatabaseFolder{"photosDatabase"};
inline const std::string sourcePhotosFolder{"sourcePhotos"};
inline const std::string logDirectoryName{"logs"};

} // namespace constants
} // namespace services
} // namespace fr

#endif // SERVICES_CONSTANTS_H
