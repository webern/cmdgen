
#include "cppcmd/ArgSpecification.h"

#include <utility>

namespace cppcmd
{
    cppcmd::ArgSpecification::ArgSpecification(
            int inMinCount,
            int inMaxCount,
            bool inIsFlag,
            std::string inFullName,
            char inShortName,
            std::string inDescription
    )
            : myMinCount{ std::max( inMinCount, 0 ) },
              myMaxCount{ std::max( inMaxCount, 0 ) },
              myIsFlag{ inIsFlag },
              myFullName{ std::move( inFullName ) },
              myShortName{ inShortName },
              myDescription{ std::move( inDescription ) }
    {
        if( myIsFlag && ( myMinCount != 0 || myMaxCount != 1 ) )
        {
            throw std::runtime_error{
                    "A flag should have min count 0 and max count 1."
            };
        }
    }


    ArgSpecification::ArgSpecification( std::string inFullName, char inShortName, std::string inDescription )
            : ArgSpecification{
            0,
            0,
            false,
            std::move( inFullName ),
            inShortName,
            std::move( inDescription ) }
    {

    }


    ArgSpecification::ArgSpecification()
            : ArgSpecification( "dummy", 'd', "" )
    {

    }


    bool
    cppcmd::ArgSpecification::getIsRequired() const
    {
        return myMinCount > 0;
    }


    int
    ArgSpecification::getMinCount() const
    {
        return myMinCount;
    }


    int
    ArgSpecification::getMaxCount() const
    {
        return myMaxCount;
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