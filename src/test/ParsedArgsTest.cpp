// cmdgen by (c) Matthew James Briggs

#include "cmdgen/ParsedArgs.h"
#include "catch.hpp"

namespace cmdgen
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

    TEST_CASE( "ParsedArgs 1" )
    {
        const ArgSpecifications argSpecifications{ ARG_SPEC_A, ARG_SPEC_B, ARG_SPEC_C };
        ParsedArgs parsedArgs{ argSpecifications };
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_A.getFullName() ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_B.getFullName() ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_C.getFullName() ) );

        auto val1 = parsedArgs.getArgVal( ARG_SPEC_A.getFullName() );
        const std::string str1 = "HELLO WORLD";
        parsedArgs.setArgVal( val1.addVal( str1 ) );
        CHECK( parsedArgs.getIsPresent( ARG_SPEC_A.getFullName() ) );
        CHECK( 1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getValueCount() );
        CHECK( str1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getValue() );
        CHECK( 1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().size() );
        CHECK( str1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().at( 0 ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_B.getFullName() ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_C.getFullName() ) );

        auto val2 = parsedArgs.getArgVal( ARG_SPEC_A.getFullName() );
        const std::string str2{ "@@" };
        parsedArgs.setArgVal( val2.addVal( str2 ) );
        CHECK( parsedArgs.getIsPresent( ARG_SPEC_A.getFullName() ) );
        CHECK( 2 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getValueCount() );
        CHECK( str1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getValue() );
        CHECK( 2 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().size() );
        CHECK( str1 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().at( 0 ) );
        CHECK( str2 == parsedArgs.getArgVal( ARG_SPEC_A.getFullName() ).getAllValues().at( 1 ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_B.getFullName() ) );
        CHECK_FALSE( parsedArgs.getIsPresent( ARG_SPEC_C.getFullName() ) );

        auto val3 = parsedArgs.getArgVal( ARG_SPEC_A.getFullName() );
        const std::string str3{ "xx" };
        parsedArgs.setArgVal( val3.addVal( str2 ) );

    }

}
