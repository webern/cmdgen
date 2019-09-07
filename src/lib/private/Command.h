// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>

struct Command
{
    std::string name;
    std::vector<Command> commands;
    
};

