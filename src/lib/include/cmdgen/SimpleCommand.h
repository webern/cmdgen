#pragma once

#include "Command.h"

namespace cmdgen
{
    class SimpleCommand : public Command
    {
    public:
        explicit SimpleCommand( ArgSpecifications inArgSpecifications );
        SimpleCommand( SimpleCommand&& other ) = default;
        [[nodiscard]] CommandPtr clone() const override;
        [[nodiscard]] CommandType getType() const override;
        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::string getDescription() const override;
        [[nodiscard]] ArgSpecifications getArgSpecifications() const override;
        [[nodiscard]] Commands getSubCommands() const override;

    private:
        ArgSpecifications myArgSpecifications;
    };
}