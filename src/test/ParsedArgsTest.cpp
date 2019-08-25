// cppcmd by (c) Matthew James Briggs

#include "cppcmd/ParsedArgs.h"
#include "catch.hpp"

namespace cppcmd
{
    const bool REQUIRED = true;
    const bool NOT_REQUIRED = false;
    const bool FLAG = true;
    const bool NOT_FLAG = false;

    const ArgSpecification ARG_SPEC_A{ REQUIRED, NOT_FLAG, "hello", 'h', "The hello message." };
    const ArgSpecification ARG_SPEC_B{ NOT_REQUIRED, FLAG, "angry", 'a', "Run program in anger mode." };
    const ArgSpecification ARG_SPEC_C( REQUIRED, NOT_FLAG, "hungry", 'u', "Run program in hunger mode." );

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
    }

}
