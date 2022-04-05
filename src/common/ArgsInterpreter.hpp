#ifndef COMMON_ARGSINTERPRETER
#define COMMON_ARGSINTERPRETER

#include <argparse/argparse.hpp>

#include "Enums.hpp"

namespace fr
{

namespace common
{

class ArgumentsInterpreter
{
public:
    ArgumentsInterpreter(int argc, char **argv);

    enums::ApplicationMode getInterpretedMode() const;

private:
    argparse::ArgumentParser m_argsParser;
};

} // namespace common
} // namespace fr

#endif
