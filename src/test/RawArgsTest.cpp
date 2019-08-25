// cppcmd by (c) Matthew James Briggs

#include "cppcmd/RawArgs.h"
#include "catch.hpp"

namespace cppcmd
{
    TEST_CASE( "RawArgs 1" )
    {
        const std::vector<std::string> input = std::vector<std::string>
                {
                        "0",
                        "hello",
                        "WORLD"
                };

        const auto rawArgs = RawArgs{ input };
        REQUIRE( 3 == rawArgs.getArgC() );
        char** argv = rawArgs.getArgV();
        CHECK( "0" == std::string{ argv[0] } );
        CHECK( "hello" == std::string{ argv[1] } );
        CHECK( "WORLD" == std::string{ argv[2] } );
        CHECK( input == rawArgs.getArgs() );
    }


    TEST_CASE( "RawArgs 2" )
    {
        const std::vector<std::string> input = std::vector<std::string>
                {
                        "0",
                        "hello",
                        "WORLD"
                };

        const auto temp = RawArgs{ input };
        char** inputArgV = temp.getArgV();
        auto inputArgC = temp.getArgC();
        std::unique_ptr<RawArgs> rawArgs = std::make_unique<RawArgs>( inputArgC, inputArgV );

        REQUIRE( 3 == rawArgs->getArgC() );
        char** argv = rawArgs->getArgV();
        CHECK( "0" == std::string{ argv[0] } );
        CHECK( "hello" == std::string{ argv[1] } );
        CHECK( "WORLD" == std::string{ argv[2] } );
        CHECK( input == rawArgs->getArgs() );
        CHECK( inputArgV == argv );
        rawArgs = nullptr;
        CHECK( rawArgs == nullptr );
        CHECK( inputArgV != nullptr );
    }
}
