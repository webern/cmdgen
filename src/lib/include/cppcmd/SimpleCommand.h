#pragma once

#include "Command.h"

namespace cppcmd
{
    class SimpleCommand : Command
    {
    public:
        SimpleCommand( ArgSpecifications inArgSpecifications );
        [[nodiscard]] virtual CommandType getType() const override;
        [[nodiscard]] virtual std::string getName() const override;
        [[nodiscard]] virtual std::string getDescription() const override;
        [[nodiscard]] virtual ArgSpecifications getArgSpecifications() const override;
        [[nodiscard]] virtual Commands getSubCommands() const override;

    private:
        ArgSpecifications myArgSpecifications;
    };
}