// cmdgen by (c) Matthew James Briggs

#include "prototype/FooExample.h"
#include "catch.hpp"

namespace
{

}

namespace foo_example
{
    int
    runGreetCommand( const GreetCommand& greetCommand )
    {
        return 0;
    }


    int
    runDieCommand( const DieCommand& dieCommand )
    {
        return 0;
    }


    TEST_CASE( "FooExample" )
    {
        const char* a = "";
        char* argv[] = { "These", "are", "some", "strings" };
        const auto result = DoMain( 4, argv );
        CHECK( result == 1 );
    }
}