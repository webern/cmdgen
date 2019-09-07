// cmdgen (c) MatthewJamesBriggs

#include "cmdgen/ArgVal.h"

namespace cmdgen
{

    ArgVal::ArgVal()
            : ArgVal{ false, "", Strings{} }
    {

    }


    ArgVal::ArgVal( bool inIsPresent, String inFullName, Strings inVals )
            : myIsPresent{ inIsPresent },
              myFullName{ std::move( inFullName ) },
              myValues{ std::move( inVals ) }
    {

    }


    const std::string&
    ArgVal::getFullName() const
    {
        return myFullName;
    }


    bool
    ArgVal::getIsPresent() const
    {
        return myIsPresent;
    }


    int
    ArgVal::getValueCount() const
    {
        return static_cast<int>(myValues.size());
    }


    std::string
    ArgVal::getValue() const
    {
        if( myValues.empty() )
        {
            return "";
        }

        return myValues.at( 0 );
    }


    Strings
    ArgVal::getAllValues() const
    {
        return myValues;
    }


    ArgVal
    ArgVal::copy() const
    {
        return ArgVal{ getIsPresent(), getFullName(), getAllValues() };
    }


    ArgVal
    ArgVal::addVal( std::string inVal ) const
    {
        Strings mutableValues = getAllValues();
        mutableValues.emplace_back( std::move( inVal ) );
        return ArgVal{ getIsPresent(), getFullName(), mutableValues };
    }
}
