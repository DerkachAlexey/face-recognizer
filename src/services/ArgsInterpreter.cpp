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

    m_argsParser.add_argument(common::constants::nameArg)
        .help("name is required parameter for registration and removal modes. "
              "Specify the name of the person to register/remove");

    try
    {
        m_argsParser.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << m_argsParser;
        std::exit(1);
    }

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

    if (foundIt == kMods.cend())
    {
        std::cerr << "invalid mode: " << modeString << std::endl;
        std::exit(1);
    }

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
    m_argsParser[common::constants::nameArg]
    .required()
    .help("enter name of the person to register");

    try
    {
        m_argsParser.parse_args({common::constants::nameArg});
    }
    catch (const std::exception& err) {
        std::cerr << m_argsParser[common::constants::nameArg];
        std::exit(1);
    }
}

void ArgumentsInterpreter::parseRemovalModeArguments()
{
    m_argsParser[common::constants::nameArg]
        .required()
        .help("enter name of the person to remove");

    try
    {
        m_argsParser.parse_args({common::constants::nameArg});
    }
    catch (const std::exception& err) {
        std::cerr << m_argsParser[common::constants::nameArg];
        std::exit(1);
    }
}

} // namespace services
} // namespace fr
