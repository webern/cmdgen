#pragma once

#include "Command.h"

namespace cppcmd
{
    class NamedLeafCommand : public Command
    {
    public:
        NamedLeafCommand( std::string inName, std::string inDescription, ArgSpecifications inArgSpecifications );
        NamedLeafCommand( NamedLeafCommand&& other ) = default;
        [[nodiscard]] CommandPtr clone() const override;
        [[nodiscard]] CommandType getType() const override;
        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::string getDescription() const override;
        [[nodiscard]] ArgSpecifications getArgSpecifications() const override;
        [[nodiscard]] Commands getSubCommands() const override;

    private:
        const std::string myName;
        const std::string myDescription;
        const ArgSpecifications myArgSpecifications;
    };
}