#include "ArgsInterpreter.hpp"
#include "Constants.hpp"

namespace fr
{

namespace common
{

ArgumentsInterpreter::ArgumentsInterpreter(int argc, char **argv):
    m_argsParser(constants::applicationName)
{
    m_argsParser.add_argument(constants::modeArg)
        .default_value<std::string>("video")
        .required()
        .help("specify the mode of application (video, photo, camera)");

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

    const auto modeString = m_argsParser.get<std::string>(constants::modeArg);
    const auto foundIt = kMods.find(modeString);

    return foundIt == kMods.cend()
               ? enums::ApplicationMode::UNKNOWN
               : foundIt->second;
}

} // namespace common
} // namespace fr
