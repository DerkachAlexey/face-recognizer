#ifndef CVDOMAIN_CONSTANTS_HPP
#define CVDOMAIN_CONSTANTS_HPP

#include <string>

namespace fr
{

namespace cvDom
{

namespace constants
{
// filesystem constants

// TODO: make reusable for different platforms
inline const std::string haarCascadesPath{"/usr/local/share/data/haarcascades/"
                                          "haarcascade_frontalface_alt.xml"};

inline const uint8_t defaultPhotoWidth{240};
inline const uint8_t defaultPhotoHeight{240};

} // namespace constants
} // namespace cvDom
} // namespace fr

#endif // CVDOMAIN_CONSTANTS_HPP
