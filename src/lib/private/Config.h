// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>
#include "Argument.h"
#include "Command.h"

namespace cmdgen
{
    struct Config
    {
        std::string program;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };
}
