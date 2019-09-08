// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>
#include "Argument.h"

namespace cmdgen
{
    struct Command
    {
        std::string name;
        std::string description;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };
}
