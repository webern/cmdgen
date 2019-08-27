// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "CommandsOrArgs.h"

namespace cppcmd
{
    class Command
    {
    public:
        Command( std::string inName, std::string inDescription );
        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] const std::string& getDescription() const;
        bool getHasSubCommands() const;
        ArgSpecifications getArgSpecifications() const;

    public:
        void addSubCommand( Command inSubcommand );

    private:
        const std::string myName;
        const std::string myDescription;
        std::vector<CommandsOrArgs> myCommandsOrArgs;
        void validate();
    };
}
