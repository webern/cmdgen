// cppcmd (c) MatthewJamesBriggs

#include "CommandsOrArgs.h"

namespace cppcmd
{
    CommandsOrArgs::CommandsOrArgs( std::vector<Command> inCommands )
            : myIsCommand{ true },
              myCommands{ std::move( inCommands ) },
              myArgSpecifications{}
    {
        validate();
    }


    CommandsOrArgs::CommandsOrArgs( std::vector<ArgSpecification> inArgSpecifications )
            : myIsCommand{ false },
              myCommands{},
              myArgSpecifications{ std::move( inArgSpecifications ) }
    {
        validate();
    }


    bool
    CommandsOrArgs::getIsCommand() const
    {
        return myIsCommand;
    }


    const std::vector<Command>&
    CommandsOrArgs::getCommands() const
    {
        if( !myIsCommand )
        {
            throw std::runtime_error{
                    "Incorrect usage: trying to get a command when you should be getting arg specs."
            };
        }
        return myCommands;
    }


    const std::vector<ArgSpecification>&
    CommandsOrArgs::getArgSpecifications() const
    {
        if( myIsCommand )
        {
            throw std::runtime_error{
                    "Incorrect usage: trying to get a arg specs when you should be getting a command."
            };
        }
        return myArgSpecifications;
    }


    void
    CommandsOrArgs::validate()
    {
        // TODO - delete if there's nothing to validate
    }
}
