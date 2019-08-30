#include "cppcmd/SimpleCommand.h"

namespace cppcmd
{
    SimpleCommand::SimpleCommand( ArgSpecifications inArgSpecifications )
            : myArgSpecifications{ std::move( inArgSpecifications ) }
    {
    }


    CommandPtr
    SimpleCommand::clone() const
    {
        return CommandPtr( new SimpleCommand( getArgSpecifications() ) );
    }


    CommandType
    SimpleCommand::getType() const
    {
        return CommandType::UNNAMED_LEAF_COMMAND;
    }


    std::string
    SimpleCommand::getName() const
    {
        return "";
    }


    std::string
    SimpleCommand::getDescription() const
    {
        return "";
    }


    ArgSpecifications
    SimpleCommand::getArgSpecifications() const
    {
        return myArgSpecifications;
    }


    Commands
    SimpleCommand::getSubCommands() const
    {
        return Commands{};
    }
}