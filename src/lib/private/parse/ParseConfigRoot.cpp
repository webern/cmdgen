// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#include "ParseConfigRoot.h"
#include "ParseCommandsOrArguments.h"
#include "ParseProgramElement.h"

namespace cmdgen
{
    Config
    ParseConfigRoot( const ezxml::XElementPtr& root )
    {
        Config config;
        if( root->getName() != "cmdgen" )
        {
            throw std::runtime_error{ "The root element should be 'cmdgen'" };
        }
        auto rootIter = root->begin();
        const auto rootEnd = root->end();
        if( rootIter == rootEnd )
        {
            throw std::runtime_error{ "The 'cmdgen' element has no children" };
        }
        if( rootIter->getName() != "program" || rootIter->begin() == rootIter->end() )
        {
            throw std::runtime_error{
                    "The first child of 'cmdgen' should be 'program' which should have sub-elements such as 'name'."
            };
        }
        else
        {
            config.program = ParseProgramElement( rootIter->begin(), rootIter->end() );
        }
        ++rootIter;
        if( rootIter == rootEnd )
        {
            std::cout << "Nothing to parse here." << std::endl;
            // TODO - is this an error?
        }
        if( rootIter->getName() == "settings" )
        {
            // TODO - parse settings
            ++rootIter;
        }
        if( rootIter->getName() != "commands" && rootIter->getName() != "arguments" )
        {
            throw std::runtime_error{ "Expected to find 'commands' or 'arguments'" };
        }
        else
        {
            ParseCommandsOrArguments( rootIter, config.commands, config.arguments );
        }
        return config;
    }
}
