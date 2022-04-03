#include "EnumNamesProvider.hpp"

#include <map>

namespace fr {

namespace services {

EnumNamesProvider::EnumNamesProvider() {}

std::string EnumNamesProvider::getName(enums::ApplicationMode mode) const {
  static const auto appModesNames =
      std::map<enums::ApplicationMode, std::string>{
          {enums::ApplicationMode::CAMERA, "camera"},
          {enums::ApplicationMode::PHOTO, "photo"},
          {enums::ApplicationMode::STREAM, "stream"},
          {enums::ApplicationMode::VIDEO, "video"},
          {enums::ApplicationMode::UNKNOWN, "unknow"}};

  return appModesNames.at(mode);
}

} // namespace services
} // namespace fr
