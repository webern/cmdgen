#include "cmdgen/Command.h"

namespace cmdgen
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