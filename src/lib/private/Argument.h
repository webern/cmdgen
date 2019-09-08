// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <vector>
#include "Type.h"

namespace cmdgen
{
    struct Argument
    {
        bool unlabeled = false;
        std::string name;
        std::string shorthand;
        std::string description;
        int minOccurs = -1;
        int maxOccurs = -1;
        Type type;
    };
}
