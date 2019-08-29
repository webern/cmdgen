#pragma once

namespace cppcmd
{
    enum class CommandType
    {
        UNNAMED_LEAF_COMMAND,            // has no name. only the root command can be an unnamed leaf
        NAMED_LEAF_COMMAND,              // has a name, can have arguments, cannot have sub-commands
        NAMED_COMMAND_WITH_SUB_COMMANDS, // has a name and sub-commands, cannot have arguments
    };


    inline bool
    canHaveSubCommands( CommandType commandType )
    {
        switch( commandType )
        {
            case CommandType::UNNAMED_LEAF_COMMAND: return false;
            case CommandType::NAMED_LEAF_COMMAND: return false;
            case CommandType::NAMED_COMMAND_WITH_SUB_COMMANDS: return true;
        }

        return false;
    }


    inline bool
    canHaveArguments( CommandType commandType )
    {
        return !canHaveSubCommands( commandType );
    }


    inline bool
    hasName( CommandType commandType )
    {
        switch( commandType )
        {
            case CommandType::UNNAMED_LEAF_COMMAND: return false;
            case CommandType::NAMED_LEAF_COMMAND:return true;
            case CommandType::NAMED_COMMAND_WITH_SUB_COMMANDS: return true;
        }

        return false;
    }
}
