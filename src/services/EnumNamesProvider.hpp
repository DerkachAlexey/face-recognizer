#ifndef SERVICES_ENUMNAMESPROVIDER
#define SERVICES_ENUMNAMESPROVIDER

#include "Enums.hpp"
#include "IService.hpp"

#include <string>

namespace fr {

namespace services {

class EnumNamesProvider : public IService {
public:
  EnumNamesProvider();

  std::string getName(enums::ApplicationMode mode) const;
};

} // namespace services
} // namespace fr

#endif
