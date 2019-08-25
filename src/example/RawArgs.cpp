// cppcmd (c) MatthewJamesBriggs

#include "RawArgs.h"

namespace cppcmd
{

    RawArgs::RawArgs( int argc, char** argv )
            : myArgC{ argc },
              myArgV{ argv },
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
}
