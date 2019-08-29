// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>

namespace cppcmd
{
    class ArgSpecification;

    struct Error;

    using String = std::string;
    using Strings = std::vector<std::string>;
    using ArgSpecifications = std::vector<ArgSpecification>;
    using Errors = std::vector<Error>;
}