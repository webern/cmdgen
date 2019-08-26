// cppcmd by (c) Matthew James Briggs

#include "cppcmd/ParsedArgs.h"
#include "parseArgs.h"
#include "catch.hpp"

namespace cppcmd
{
    const bool IS_FLAG = true;
    const bool IS_NOT_FLAG = false;

    const ArgSpecification ARG_SPEC_A(
            0,
            2,
            IS_NOT_FLAG,
            "hello",
            'h',
            "The hello message."
    );

    const ArgSpecification ARG_SPEC_B(
            0,
            1,
            IS_FLAG,
            "angry",
            'a',
            "Run program in anger mode."
    );

    const ArgSpecification ARG_SPEC_C(
            "hungry",
            'u',
            "Run program in hunger mode."
    );

    const ArgSpecification ARG_SPEC_D(
            1,
            0,
            IS_NOT_FLAG,
            "many-things",
            'm',
            "Many things can go here, at least one is required."
    );

    const ArgSpecifications ARG_SPECS{ ARG_SPEC_A, ARG_SPEC_B, ARG_SPEC_C, ARG_SPEC_D };

    TEST_CASE( "parseArgs 1" )
    {
        const Strings input{
                "/my/app/executable",
                "--angry",
                "-m",
                "m 1",
                "-m",
                "m 2",
                "-u",
                "i am hungry",
                "-m",
                "m 3",
                "-h",
                "HELLO WORLD"
        };
        RawArgs rawArgs{ input };
        const auto parsedArgs = parseArgs( ARG_SPECS, rawArgs );
        CHECK_FALSE( parsedArgs.getIsError() );
        REQUIRE( 1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().size() );
        CHECK( parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getIsPresent() );
        CHECK( "HELLO WORLD" == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getValue() );

        CHECK( 0 == parsedArgs.getArgVal( ARG_SPEC_B.getFullName() ).getAllValues().size() );
        CHECK( parsedArgs.getArgVal( ARG_SPEC_B.getFullName() ).getIsPresent() );

        REQUIRE( 1 == parsedArgs.getArgVal( ARG_SPEC_C.getFullName() ).getAllValues().size() );
        CHECK( parsedArgs.getArgVal( ARG_SPEC_C.getFullName() ).getIsPresent() );
        CHECK( "i am hungry" == parsedArgs.getArgVal( ARG_SPEC_C.getFullName() ).getValue() );

        REQUIRE( 3 == parsedArgs.getArgVal( ARG_SPEC_D.getFullName() ).getAllValues().size() );
        CHECK( parsedArgs.getArgVal( ARG_SPEC_D.getFullName() ).getIsPresent() );
        CHECK( "m 1" == parsedArgs.getArgVal( ARG_SPEC_D.getFullName() ).getValue() );
        CHECK( "m 2" == parsedArgs.getArgVal( ARG_SPEC_D.getFullName() ).getAllValues().at( 1 ) );
        CHECK( "m 3" == parsedArgs.getArgVal( ARG_SPEC_D.getFullName() ).getAllValues().at( 2 ) );
    }
}
