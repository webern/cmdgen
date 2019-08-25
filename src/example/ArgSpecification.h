// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "Command.h"
#include "ArgSpecification.h"

namespace cppcmd
{
    class ArgSpecification
    {
    public:
        ArgSpecification(
                bool inIsRequired,
                bool inIsFlag,
                std::string inFullName,
                char inShortName,
                std::string inDescription
        );

    public:
        [[nodiscard]] bool getIsRequired() const;
        [[nodiscard]] bool getIsFlag() const;
        [[nodiscard]] const std::string& getFullName() const;
        [[nodiscard]] char getShortName() const;
        [[nodiscard]] const std::string& getDescription() const;

    private:
        const bool myIsFlag;
        const bool myIsRequired;
        const std::string myFullName;
        const char myShortName;
        const std::string myDescription;
    };
}
