// cmdgen (c) MatthewJamesBriggs

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Typedef.h"

namespace cmdgen
{

    class ArgVal
    {
    public:
        ArgVal();
        explicit ArgVal( bool inIsPresent, std::string inFullName, Strings inVals );
        [[nodiscard]] const std::string& getFullName() const;
        [[nodiscard]] bool getIsPresent() const;
        [[nodiscard]] int getValueCount() const;
        [[nodiscard]] std::string getValue() const;
        [[nodiscard]] Strings getAllValues() const;
        [[nodiscard]] ArgVal copy() const;
        ArgVal addVal( std::string inVal ) const;

    private:
        const bool myIsPresent;
        const std::string myFullName;
        const Strings myValues;
    };
}
