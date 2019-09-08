// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#include "ParseProgramElement.h"

namespace cmdgen
{
    ProgramElement
    ParseProgramElement(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end
    )
    {
        ProgramElement program{};
        for( ; iter != end; ++iter )
        {
            if( iter->getName() == "name" )
            {
                program.name = iter->getValue();
            }
            else if( iter->getName() == "description" )
            {
                program.description = iter->getValue();
            }
        }
        return program;
    }
}
