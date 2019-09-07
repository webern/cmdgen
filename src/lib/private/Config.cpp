// cmdgen (c) MatthewJamesBriggs

#include "cmdgen/Config.h"

namespace cmdgen
{
    Config::Config(
            std::string inAppName,
            std::string inAppDescription,
            Commands&& inCommands
    )
            : myAppName( std::move( inAppName ) ),
              myAppDescription( std::move( inAppDescription ) ),
              myCommands{ std::move( inCommands ) }
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
}
