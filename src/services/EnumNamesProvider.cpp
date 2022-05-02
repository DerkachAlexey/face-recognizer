#include "services/EnumNamesProvider.hpp"

#include <map>

namespace fr
{

namespace services
{

std::string EnumNamesProvider::getName(enums::ApplicationMode mode) const {
  static const auto appModesNames =
      std::map<enums::ApplicationMode, std::string>{
          {enums::ApplicationMode::REGISTRATION, "registration"},
          {enums::ApplicationMode::RECOGNITION, "recognition"},
          {enums::ApplicationMode::REMOVAL, "removal"},
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

std::string EnumNamesProvider::getName(enums::Extensions extension) const
{
    static const auto extensionNames =
        std::map<enums::Extensions, std::string>{
            {enums::Extensions::JPG, "jpg"},
            {enums::Extensions::PNG, "png"}};

    return extensionNames.at(extension);
}

} // namespace services
} // namespace fr
