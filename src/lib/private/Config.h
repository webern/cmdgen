// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>
#include "Argument.h"
#include "Command.h"
#include "ProgramElement.h"

namespace cmdgen
{
    struct Config
    {
        ProgramElement program;
        std::string description;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };
}
