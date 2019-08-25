// cppcmd (c) MatthewJamesBriggs

#include "cppcmd/ParsedArgs.h"

namespace cppcmd
{
    ParsedArgs::ParsedArgs( const ArgSpecifications& inArgSpecifications )
            : myArgMap{ createArgMap( inArgSpecifications ) }
    {

    }


    bool
    ParsedArgs::getIsPresent( const std::string& inFullName ) const
    {
        return getArgVal( inFullName ).getIsPresent();
    }


    ArgVal
    ParsedArgs::getArgVal( const std::string& inFullName ) const
    {
        const auto finder = myArgMap.find( inFullName );

        if( finder == myArgMap.cend() )
        {
            return ArgVal{ false, inFullName, Strings{} };
        }

        return finder->second.copy();
    }


    void
    ParsedArgs::setArgVal( const ArgVal& inArgVal )
    {
        const auto current = getArgVal( inArgVal.getFullName() );
        ArgVal updated{ true, inArgVal.getFullName(), inArgVal.getAllValues() };
        myArgMap.erase( myArgMap.find( inArgVal.getFullName() ) );
        myArgMap.emplace( inArgVal.getFullName(), std::move( updated ) );
    }


    ParsedArgs::ArgMap
    ParsedArgs::createArgMap( const ArgSpecifications& inArgSpecifications )
    {
        ArgMap argMap{};

        for( const auto& argSpec : inArgSpecifications )
        {
            argMap.emplace( argSpec.getFullName(), ArgVal{ false, argSpec.getFullName(), Strings{} } );
        }

        return argMap;
    }
}
