// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#include "ParseCommandsOrArguments.h"
#include "ParseCommands.h"
#include "ParseArguments.h"

namespace cmdgen
{
    void
    ParseCommandsOrArguments(
            const ezxml::XElementIterator& iter,
            std::vector<Command>& ioCommands,
            std::vector<Argument>& ioArguments
    )
    {
        if( iter->getName() == "commands" )
        {
            ParseCommands( iter->begin(), iter->end(), ioCommands );
        }
        else if( iter->getName() == "arguments" )
        {
            ParseArguments( iter->begin(), iter->end(), ioArguments );
        }
        else
        {
            throw std::runtime_error{ "Expected 'commands' or 'arguments'." };
        }
    }
}
