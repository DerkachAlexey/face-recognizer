#ifndef COMMON_ARGSINTERPRETER
#define COMMON_ARGSINTERPRETER

#include "services/IService.hpp"

#include <argparse/argparse.hpp>

#include "common/Enums.hpp"

namespace fr
{

namespace services
{

class ArgumentsInterpreter : public IService
{
public:
    ArgumentsInterpreter(int argc, char **argv);

    fr::enums::ApplicationMode getInterpretedMode() const;
    std::string getNameToRegister() const;
    std::string getNameToRemove() const;

private:
    void parseRegistrationArguments();
    void parseRemovalModeArguments();

private:
    argparse::ArgumentParser m_argsParser;
    argparse::ArgumentParser m_registrationParser;
    argparse::ArgumentParser m_removalParser;
};

} // namespace services
} // namespace fr

#endif
