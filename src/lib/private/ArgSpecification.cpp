
#include "cppcmd/ArgSpecification.h"

namespace cppcmd
{
    cppcmd::ArgSpecification::ArgSpecification(
            bool inIsRequired,
            bool inIsFlag,
            std::string inFullName,
            char inShortName,
            std::string inDescription
    )
            : myIsRequired{ inIsRequired },
              myIsFlag{ inIsFlag },
              myFullName{ std::move( inFullName ) },
              myShortName{ inShortName },
              myDescription{ std::move( inDescription ) }
    {
        if( myIsFlag && myIsRequired )
        {
            throw std::runtime_error{
                    "It doesn't make sense for an argument to be both a flag and required (always true)."
            };
        }
    }


    bool
    cppcmd::ArgSpecification::getIsRequired() const
    {
        return myIsRequired;
    }


    bool
    cppcmd::ArgSpecification::getIsFlag() const
    {
        return myIsFlag;
    }


    const std::string&
    cppcmd::ArgSpecification::getFullName() const
    {
        return myFullName;
    }


    char
    cppcmd::ArgSpecification::getShortName() const
    {
        return myShortName;
    }


    const std::string&
    cppcmd::ArgSpecification::getDescription() const
    {
        return myDescription;
    }
}