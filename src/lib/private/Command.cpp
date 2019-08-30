#include "cppcmd/Command.h"

namespace cppcmd
{
    Commands
    copyCommands( const Commands& inCommands )
    {
        Commands commands;
        for( const auto& c : inCommands )
        {
            commands.emplace_back( c->clone() );
        }
        return commands;
    }
}