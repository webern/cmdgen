// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#include "ParseArguments.h"

namespace cmdgen
{
    Argument
    ParseArgument(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end,
            bool isUnflagged
    )
    {
        Argument argument;
        argument.unlabeled = isUnflagged;
        for( ; iter != end; ++iter )
        {
            if( iter->getName() == "name" )
            {
                argument.name = iter->getValue();
            }
            else if( iter->getName() == "description" )
            {
                argument.description = iter->getValue();
            }
            else if( iter->getName() == "min-occurs" )
            {
                const std::string strVal = iter->getValue();
                const int val = std::stoi( strVal );
                argument.minOccurs = val;
            }
            else if( iter->getName() == "max-occurs" )
            {
                const std::string strVal = iter->getValue();
                const int val = std::stoi( strVal );
                argument.maxOccurs = val;
            }
            else if( iter->getName() == "type" )
            {
                const auto t = ParseType( iter->getValue() );
                if( t == Type::ERROR )
                {
                    throw std::runtime_error{ "Bad 'type' value '" + iter->getValue() + "'" };
                }
                argument.type = t;
            }
            else if( iter->getName() == "default" )
            {
                argument.defaultValue = iter->getValue();
            }
            else if( iter->getName() == "shorthand" )
            {
                argument.shorthand = iter->getValue();
            }
        }

        return argument;
    }


    void
    ParseArguments(
            ezxml::XElementIterator iter,
            const ezxml::XElementIterator& end,
            std::vector<Argument>& ioArguments
    )
    {
        for( ; iter != end; ++iter )
        {
            if( iter->getName() == "argument" )
            {
                ioArguments.emplace_back( ParseArgument( iter->begin(), iter->end(), false ) );
            }
            else if( iter->getName() == "unlabeled" )
            {
                ioArguments.emplace_back( ParseArgument( iter->begin(), iter->end(), true ) );
            }
            else
            {
                throw std::runtime_error{ "Expected 'unlabeled' or 'argument'." };
            }
        }
    }
}
