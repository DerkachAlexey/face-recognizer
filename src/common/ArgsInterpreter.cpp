#include "ArgsInterpreter.hpp"
#include "Constants.hpp"

namespace fr {
namespace common {
ArgumentsInterpreter::ArgumentsInterpreter(int argc, char **argv)
    : m_argsParser(constants::applicationName)
{
    m_argsParser.add_argument("-m", "--mode")
        .default_value<std::string>("video")
        .required()
        .help("specify the mode of application (video, photo, camera)");

    //TODO: implement parsing of additional args

//    m_argsParser.add_argument("--src")
//        .default_value<std::vector<std::string>>({constants::defaultSrcFolder})
//        .append()
//        .help("specify the source file of a video/photo/camera");

    m_argsParser.parse_args(argc, argv);
}

enums::ApplicationMode ArgumentsInterpreter::getInterpretedMode() const
{
    static const std::map<std::string, enums::ApplicationMode> kMods
    {
            {"video", enums::ApplicationMode::VIDEO},
            {"photo", enums::ApplicationMode::PHOTO},
            {"camera", enums::ApplicationMode::CAMERA},
            {"stream", enums::ApplicationMode::STREAM}
    };

    const auto modeString = m_argsParser.get<std::string>("--mode");
    const auto foundIt = kMods.find(modeString);

    return foundIt == kMods.cend()
               ? enums::ApplicationMode::UNKNOWN
               : foundIt->second;
}
} // namespace common
} // namespace fr
