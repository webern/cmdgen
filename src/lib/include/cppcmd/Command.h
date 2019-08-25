// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>

namespace cppcmd
{
    class Command
    {
    public:
        Command( std::string inName, std::string inDescription );
        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] const std::string& getDescription() const;
        [[nodiscard]] const std::vector<Command>& getSubCommands() const;

    public:
        void addSubCommand( Command inSubcommand );

    private:
        const std::string myName;
        const std::string myDescription;
        std::vector<Command> mySubCommands;
        void validate();
    };
}
