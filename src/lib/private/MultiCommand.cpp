#include "cppcmd/MultiCommand.h"

namespace cppcmd
{
    MultiCommand::MultiCommand(
            std::string inName,
            std::string inDescription,
            Commands&& inSubCommands
    )
            : myName{ std::move( inName ) },
              myDescription{ std::move( inDescription ) },
              mySubCommands{ std::move( inSubCommands ) }
    {
        if( myName.empty() )
        {
            throw std::runtime_error( "NamedLeafCommand cannot have an empty name" );
        }
    }


    CommandPtr
    MultiCommand::clone() const
    {
        return CommandPtr( new MultiCommand( getName(), getDescription(), getSubCommands() ) );
    }


    CommandType
    MultiCommand::getType() const
    {
        return CommandType::NAMED_LEAF_COMMAND;
    }


    std::string
    MultiCommand::getName() const
    {
        return myName;
    }


    std::string
    MultiCommand::getDescription() const
    {
        return myDescription;
    }


    ArgSpecifications
    MultiCommand::getArgSpecifications() const
    {
        return ArgSpecifications{};
    }


    Commands
    MultiCommand::getSubCommands() const
    {
        return copyCommands( mySubCommands );
    }
}