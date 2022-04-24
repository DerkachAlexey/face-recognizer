#include "EnumNamesProvider.hpp"

#include <map>

namespace fr
{

namespace services
{

std::string EnumNamesProvider::getName(enums::ApplicationMode mode) const {
  static const auto appModesNames =
      std::map<enums::ApplicationMode, std::string>{
          {enums::ApplicationMode::CAMERA, "camera"},
          {enums::ApplicationMode::PHOTO, "photo"},
          {enums::ApplicationMode::STREAM, "stream"},
          {enums::ApplicationMode::VIDEO, "video"},
          {enums::ApplicationMode::REGISTRATION, "registration"},
          {enums::ApplicationMode::UNKNOWN, "unknow"}};

  return appModesNames.at(mode);
}

std::string EnumNamesProvider::getName(cvDom::enums::CameraType cameraType) const
{
    static const auto camerasNames =
        std::map<cvDom::enums::CameraType, std::string>{
            {cvDom::enums::CameraType::WEB_CAMERA, "Web camera"},
            {cvDom::enums::CameraType::USB_CAMERA, "Usb camera"},
            {cvDom::enums::CameraType::UNKNOW, "Unknow camera"}};

    return camerasNames.at(cameraType);
}

} // namespace services
} // namespace fr
