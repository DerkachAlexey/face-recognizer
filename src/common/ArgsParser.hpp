#ifndef COMMON_ARGSPARSER
#define COMMON_ARGSPARSER

#include <argparse/argparse.hpp>

namespace fr {
namespace common {

class ArgsParser
{
public:
    ArgsParser(int argc, char **argv);

private:
    argparse::ArgumentParser m_argsParser;
};

} // namespace common
} // namespace fr

#endif
