#pragma once

#include "Command.h"

namespace cmdgen
{
    class MultiCommand : public Command
    {
    public:
        MultiCommand( std::string inName, std::string inDescription, Commands&& inSubCommands );
        MultiCommand( MultiCommand&& other ) = default;
        [[nodiscard]] CommandPtr clone() const override;
        [[nodiscard]] CommandType getType() const override;
        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::string getDescription() const override;
        [[nodiscard]] ArgSpecifications getArgSpecifications() const override;
        [[nodiscard]] Commands getSubCommands() const override;

    private:
        const std::string myName;
        const std::string myDescription;
        const Commands mySubCommands;
    };
}