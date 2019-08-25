// cppcmd (c) MatthewJamesBriggs

#include "Config.h"

namespace cppcmd
{
    Config::Config(
            std::string inAppName,
            std::string inAppDescription,
            CommandsOrArgs inCommandsOrArgs
    )
            : myAppName( std::move( inAppName ) ),
              myAppDescription( std::move( inAppDescription ) ),
              myCommandsOrArgs( std::move( inCommandsOrArgs ) )
    {
    }


    const std::string&
    Config::getAppName() const
    {
        return myAppName;
    }


    const std::string&
    Config::getAppDescription() const
    {
        return myAppDescription;
    }


    const CommandsOrArgs&
    Config::getCommandsOrArgs() const
    {
        return myCommandsOrArgs;
    }

}
