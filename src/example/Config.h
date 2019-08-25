// cppcmd (c) MatthewJamesBriggs

#pragma once

#include "Command.h"
#include "CommandsOrArgs.h"
#include <string>
#include <vector>

namespace cppcmd
{
    class Config
    {
    public:
        Config( std::string inAppName, std::string inAppDescription, CommandsOrArgs inCommandOrArgs );
        [[nodiscard]] const std::string& getAppName() const;
        [[nodiscard]] const std::string& getAppDescription() const;
        [[nodiscard]] const CommandsOrArgs& getCommandsOrArgs() const;

    private:
        const std::string myAppName;
        const std::string myAppDescription;
        const CommandsOrArgs myCommandsOrArgs;
    };
}
