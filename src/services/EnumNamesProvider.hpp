#ifndef SERVICES_ENUMNAMESPROVIDER
#define SERVICES_ENUMNAMESPROVIDER

#include "common/Enums.hpp"
#include "cvDomain/Enums.hpp"
#include "IService.hpp"

#include <string>

namespace fr
{

namespace services
{

class EnumNamesProvider : public IService
{
public:
  EnumNamesProvider() = default;

  std::string getName(enums::ApplicationMode mode) const;
  std::string getName(cvDom::enums::CameraType cameraType) const;
};

} // namespace services
} // namespace fr

#endif
