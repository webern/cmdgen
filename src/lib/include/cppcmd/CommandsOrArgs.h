// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "cppcmd/Command.h"
#include "cppcmd/ArgSpecification.h"

namespace cppcmd
{
    class CommandsOrArgs
    {
    public:
        explicit CommandsOrArgs( std::vector<Command> inCommands );
        explicit CommandsOrArgs( std::vector<ArgSpecification> inArgSpecifications );

    private:
        const bool myIsCommand;
    public:
        [[nodiscard]] bool getIsCommand() const;
        [[nodiscard]] const std::vector<Command>& getCommands() const;
        [[nodiscard]] const std::vector<ArgSpecification>& getArgSpecifications() const;
    private:
        const std::vector<Command> myCommands;
        const std::vector<ArgSpecification> myArgSpecifications;
        void validate();
    };
}
