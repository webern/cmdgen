// cppcmd (c) MatthewJamesBriggs

#include "cppcmd/Command.h"

namespace cppcmd
{

    Command::Command( std::string inName, std::string inDescription )
            : myName{ std::move( inName ) },
              myDescription{ std::move( inDescription ) }
    {
        validate();
    }


    const std::string&
    Command::getName() const
    {
        return myName;
    }


    const std::string&
    Command::getDescription() const
    {
        return myDescription;
    }


    const std::vector<Command>&
    Command::getSubCommands() const
    {
        return mySubCommands;
    }


    void
    Command::addSubCommand( Command inSubcommand )
    {
        mySubCommands.emplace_back( std::move( inSubcommand ) );
    }


    void
    Command::validate()
    {
        if( myName.empty() )
        {
            throw std::runtime_error{ "A command must have a name" };
        }
    }
}
