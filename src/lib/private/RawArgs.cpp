// cppcmd (c) MatthewJamesBriggs

#include "cppcmd/RawArgs.h"

namespace cppcmd
{

    RawArgs::RawArgs( int argc, char** argv )
            : myArgC{ argc },
              myArgV{ argv },
              myIsArgVOwned{ false },
              myArgs{}
    {
        for( int i = 0; i < argc; ++i )
        {
            const auto current = myArgV[static_cast<size_t>(i)];
            myArgs.emplace_back( std::string{ current } );
        }
    }


    RawArgs::RawArgs( std::vector<std::string> inArgs )
            : myArgC{ static_cast<int>(inArgs.size()) },
              myArgV{ nullptr },
              myIsArgVOwned{ true },
              myArgs{ std::move( inArgs ) }
    {
        myArgV = (char**)malloc( myArgC * sizeof( char* ) );
        for( size_t i = 0; i < myArgs.size(); ++i )
        {
            const char* const current = myArgs.at( i ).c_str();
            const size_t currentCLen = myArgs.at( i ).size() + 1;
            char* copy = (char*)malloc( sizeof( char* ) * currentCLen );
            std::memcpy( copy, current, currentCLen );
            myArgV[i] = copy;
        }
    }


    RawArgs::~RawArgs()
    {
        if( !myIsArgVOwned || !myArgV )
        {
            return;
        }

        for( size_t i = 0; i < static_cast<size_t>(myArgC); ++i )
        {
            delete myArgV[i];
        }

        delete myArgV;
    }


    const std::vector<std::string>&
    RawArgs::getArgs() const
    {
        return myArgs;
    }


    int
    RawArgs::getArgC() const
    {
        return myArgC;
    }


    char**
    RawArgs::getArgV() const
    {
        return myArgV;
    }
}
