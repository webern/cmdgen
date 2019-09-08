// cmdgen by (c) Matthew James Briggs

#include <iostream>
#include "cmdgen/Placeholder.h"
#include "ezxml/ezxml.h"

namespace
{
    static constexpr const char* const CMDGEN_USAGE = "usage: cppgen --input input/file/path.xml --lang c++";


    static inline void
    streamUsage( const char* const error, std::ostream& os )
    {
        std::cout << error << std::endl;
        std::cout << CMDGEN_USAGE << std::endl;
    }


    constexpr const char* const WRONG_ARGS_OR_NO_INPUT_FLAG_MESSAGE = "wrong args or no --input";
    constexpr const int WRONG_ARGS_OR_NO_INPUT_FLAG = 100;
    constexpr const char* const NO_LANG_FLAG_MESSAGE = "no --lang";
    constexpr const int NO_LANG_FLAG = 101;
    constexpr const char* const UNSUPPORTED_LANGUAGE_MESSAGE = "unsupported language. supported: C++";
    constexpr const int UNSUPPORTED_LANGUAGE = 102;
}


int
main( int argc, char* argv[] )
{
    using namespace cmdgen;
    Placeholder::print();

    if( argc != 5 || std::string{ argv[1] } != "--input" )
    {
        streamUsage( WRONG_ARGS_OR_NO_INPUT_FLAG_MESSAGE, std::cout );
        return WRONG_ARGS_OR_NO_INPUT_FLAG;
    }

    const std::string input{ argv[2] };

    if( std::string{ argv[3] } != "--lang" )
    {
        streamUsage( NO_LANG_FLAG_MESSAGE, std::cout );
        return NO_LANG_FLAG;
    }

    const std::string lang{ argv[3] };

    if( lang != "c++" && lang != "C++" )
    {
        streamUsage( UNSUPPORTED_LANGUAGE_MESSAGE, std::cout );
        return UNSUPPORTED_LANGUAGE;
    }
}