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
        .required()
        .help("specify the mode of application (registration, removal, recognition)");

    m_argsParser.add_argument(common::constants::nameArg);

    m_argsParser.parse_args(argc, argv);

    switch(getInterpretedMode())
    {
    case enums::ApplicationMode::REGISTRATION:
        parseRegistrationArguments();
        break;
    case enums::ApplicationMode::REMOVAL:
        parseRemovalModeArguments();
        break;
    default:
        return;
    }
}

enums::ApplicationMode ArgumentsInterpreter::getInterpretedMode() const
{
    static const std::map<std::string, enums::ApplicationMode> kMods
    {           
            {"registration", enums::ApplicationMode::REGISTRATION},
            {"recognition", enums::ApplicationMode::RECOGNITION},
            {"removal", enums::ApplicationMode::REMOVAL}
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

std::string ArgumentsInterpreter::getNameToRemove() const
{
    return m_removalParser.get<std::string>(
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

void ArgumentsInterpreter::parseRemovalModeArguments()
{
    m_removalParser = argparse::ArgumentParser("removal");
    m_removalParser.add_argument(common::constants::nameArg)
        .required()
        .help("enter name of the person to remove from DB");

    m_removalParser.add_parents(m_argsParser);

    m_removalParser.parse_args({common::constants::nameArg});
}

} // namespace services
} // namespace fr
