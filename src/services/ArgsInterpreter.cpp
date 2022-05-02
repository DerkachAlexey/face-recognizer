#include "services/ArgsInterpreter.hpp"
#include "common/Constants.hpp"

namespace fr
{

namespace services
{

ArgumentsInterpreter::ArgumentsInterpreter(int argc, char **argv):
      m_argsParser(common::constants::applicationName)
{
    m_argsParser.add_argument(common::constants::modeArg)
        .default_value<std::string>("video")
        .required()
        .help("specify the mode of application (video, photo, camera)");

    m_argsParser.add_argument(common::constants::nameArg)
        .help("enter name of the person to register");

    m_argsParser.parse_args(argc, argv);

    switch(getInterpretedMode())
    {
    case enums::ApplicationMode::REGISTRATION:
        parseRegistrationArguments();
    default:
        return;
    }
}

enums::ApplicationMode ArgumentsInterpreter::getInterpretedMode() const
{
    static const std::map<std::string, enums::ApplicationMode> kMods
    {           
            {"registration", enums::ApplicationMode::REGISTRATION},
            {"recognition", enums::ApplicationMode::RECOGNITION}
    };

    const auto modeString = m_argsParser.get<std::string>(
        common::constants::modeArg);
    const auto foundIt = kMods.find(modeString);

    return foundIt == kMods.cend()
               ? enums::ApplicationMode::UNKNOWN
               : foundIt->second;
}

std::string services::ArgumentsInterpreter::getNameToRegister() const
{
    return m_registrationParser.get<std::string>(
        common::constants::nameArg);
}

void services::ArgumentsInterpreter::parseRegistrationArguments()
{
    m_registrationParser = argparse::ArgumentParser("registration");
    m_registrationParser.add_argument(common::constants::nameArg)
        .required()
        .help("enter name of the person to register");

    m_registrationParser.add_parents(m_argsParser);

    m_registrationParser.parse_args({common::constants::nameArg});
}

} // namespace services
} // namespace fr
