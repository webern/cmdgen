// cppcmd (c) MatthewJamesBriggs

#include "cppcmd/Config.h"

namespace cppcmd
{
    Config::Config(
            std::string inAppName,
            std::string inAppDescription
    )
            : myAppName( std::move( inAppName ) ),
              myAppDescription( std::move( inAppDescription ) )
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
