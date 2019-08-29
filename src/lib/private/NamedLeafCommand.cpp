#include "cppcmd/NamedLeafCommand.h"

namespace cppcmd
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