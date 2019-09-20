// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>
#include "Argument.h"
#include "Command.h"
#include "Program.h"

namespace cmdgen
{
    struct CmdGen
    {
        Program program;
        std::string description;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };
}
