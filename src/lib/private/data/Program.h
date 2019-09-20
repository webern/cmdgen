// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>

namespace cmdgen
{
    struct Program
    {
        std::string name;
        std::string description;
        std::vector<std::string> examples;
    };
}
