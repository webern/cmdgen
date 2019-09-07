#include "cmdgen/NamedLeafCommand.h"

namespace cmdgen
{
    NamedLeafCommand::NamedLeafCommand(
            std::string inName,
            std::string inDescription,
            ArgSpecifications inArgSpecifications
    )
            : myName{ std::move( inName ) },
              myDescription{ std::move( inDescription ) },
              myArgSpecifications{ std::move( inArgSpecifications ) }
    {
        if( myName.empty() )
        {
            throw std::runtime_error( "NamedLeafCommand cannot have an empty name" );
        }
    }


    CommandPtr
    NamedLeafCommand::clone() const
    {
        return CommandPtr( new NamedLeafCommand( getName(), getDescription(), getArgSpecifications() ) );
    }


    CommandType
    NamedLeafCommand::getType() const
    {
        return CommandType::NAMED_LEAF_COMMAND;
    }


    std::string
    NamedLeafCommand::getName() const
    {
        return myName;
    }


    std::string
    NamedLeafCommand::getDescription() const
    {
        return myDescription;
    }


    ArgSpecifications
    NamedLeafCommand::getArgSpecifications() const
    {
        return myArgSpecifications;
    }


    Commands
    NamedLeafCommand::getSubCommands() const
    {
        return Commands{};
    }

}