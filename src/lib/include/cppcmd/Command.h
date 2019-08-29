// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <string>
#include <vector>
#include "Typedef.h"
#include "ArgSpecification.h"
#include "CommantType.h"

namespace cppcmd
{
    class Command;

    using CommandPtr = std::unique_ptr<const Command>;
    using Commands = std::vector<CommandPtr>;

    class Command
    {
    public:
        virtual ~Command() = default;
        [[nodiscard]] virtual CommandType getType() const = 0;


        inline bool getIsNamed()
        {
            return hasName( getType() );
        }


        inline bool getIsLeaf()
        {
            return canHaveSubCommands( getType() );
        }


        // getName is only relevant for named commands, returns an empty string if function is not named
        [[nodiscard]] virtual std::string getName() const = 0;

        // getDescription is only relevant for named commands, returns an empty string if function is not named
        [[nodiscard]] virtual std::string getDescription() const = 0;

        // getArgSpecifications is only relevant for leaf commands, an empty vector will be returned if not leaf command
        [[nodiscard]] virtual ArgSpecifications getArgSpecifications() const = 0;

        // getSubCommands is only relevant for non-leaf commands, an empty vector will be returned if leaf command
        [[nodiscard]] virtual Commands getSubCommands() const = 0;
    };
}
