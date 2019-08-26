// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "ArgSpecification.h"

namespace cppcmd
{
    struct Error
    {
        int rawArgsIndex;
        std::string rawArgsValue;
        std::string message;
    };
}