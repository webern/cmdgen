// cmdgen (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "cmdgen/Command.h"

namespace cmdgen
{
    class ArgSpecification
    {
    public:
        ArgSpecification(
                int inMinCount,
                int inMaxCount,
                bool inIsFlag,
                std::string inFullName,
                char inShortName,
                std::string inDescription
        );

        ArgSpecification(
                std::string inFullName,
                char inShortName,
                std::string inDescription
        );

        ArgSpecification();

    public:
        [[nodiscard]] bool getIsRequired() const;
        [[nodiscard]] int getMinCount() const;
        [[nodiscard]] int getMaxCount() const;
        [[nodiscard]] bool getIsFlag() const;
        [[nodiscard]] const std::string& getFullName() const;
        [[nodiscard]] char getShortName() const;
        [[nodiscard]] const std::string& getDescription() const;

    private:
        const int myMinCount;
        const int myMaxCount;
        const bool myIsFlag;
        const std::string myFullName;
        const char myShortName;
        const std::string myDescription;
    };
}
