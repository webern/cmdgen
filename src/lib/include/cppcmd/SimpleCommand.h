#pragma once

#include "Command.h"

namespace cppcmd
{
    class SimpleCommand : Command
    {
    public:
        SimpleCommand( ArgSpecifications inArgSpecifications );
        [[nodiscard]] CommandType getType() const override;
        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::string getDescription() const override;
        [[nodiscard]] ArgSpecifications getArgSpecifications() const override;
        [[nodiscard]] Commands getSubCommands() const override;

    private:
        ArgSpecifications myArgSpecifications;
    };
}