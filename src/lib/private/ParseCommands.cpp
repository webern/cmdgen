// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#include "ParseCommands.h"
#include "ParseArguments.h"

namespace cmdgen
{
    Command
    ParseCommand(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end

    )
    {
        Command command;
        for( ; iter != end; ++iter )
        {
            if( iter->getName() == "name" )
            {
                command.name = iter->getValue();
            }
            else if( iter->getName() == "description" )
            {
                command.description = iter->getName();
            }
            else if( iter->getName() == "arguments" )
            {
                ParseArguments( iter->begin(), iter->end(), command.arguments );
            }
            else if( iter->getName() == "commands" )
            {
                ParseCommands( iter->begin(), iter->end(), command.commands );
            }
        }

        return command;
    }


    void
    ParseCommands(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end,
            std::vector<Command>& ioCommands
    )
    {
        for( ; iter != end; ++iter )
        {
            if( iter->getName() != "command" )
            {
                throw std::runtime_error{ "'command' was expected" };
            }
            else
            {
                ioCommands.emplace_back( ParseCommand( iter->begin(), iter->end() ) );
            }
        }
    }
}
