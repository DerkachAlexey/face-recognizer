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

private:
    void parseRegistrationArguments();

private:
    argparse::ArgumentParser m_argsParser;
    argparse::ArgumentParser m_registrationParser;
};

} // namespace services
} // namespace fr

#endif
