// cmdgen (c) MatthewJamesBriggs

#pragma once

#include "cmdgen/Command.h"
#include <string>
#include <vector>

namespace cmdgen
{
    class Config
    {
    public:
        Config( std::string inAppName, std::string inAppDescription, Commands&& inCommands );
        [[nodiscard]] const std::string& getAppName() const;
        [[nodiscard]] const std::string& getAppDescription() const;

    private:
        const std::string myAppName;
        const std::string myAppDescription;
        const Commands myCommands;
    };
}
