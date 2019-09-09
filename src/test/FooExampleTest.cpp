// cmdgen by (c) Matthew James Briggs

#include "prototype/FooExample.h"
#include "catch.hpp"
#include <sstream>

namespace
{
    constexpr const int GREET_RESULT = 3131;
    constexpr const int DIE_RESULT = 2121;
}

namespace foo_example
{
    int
    runGreetCommand( const GreetCommand& greetCommand )
    {
        return GREET_RESULT;
    }


    int
    runDieCommand( const DieCommand& dieCommand )
    {
        return DIE_RESULT;
    }


    TEST_CASE( "FooExample1" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string greeting = "hello THERE!!";
        const int argc = 4;
        const char* a = "/usr/local/bin/foo";
        const char* b = "greet";
        const char* c = "--greeting";
        const char* d = greeting.c_str();

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b),
                const_cast<char*>(c),
                const_cast<char*>(d)
        };

        const auto parsed = ParseArgs( argc, argv );
        REQUIRE( std::holds_alternative<GreetCommand>( parsed.command ) );
        CHECK_FALSE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& greet = std::get<GreetCommand>( parsed.command );
        CHECK( greeting == greet.greeting );
        CHECK_FALSE( greet.times );
        CHECK( 1 == greet.timesDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == GREET_RESULT );
    }


    TEST_CASE( "FooExample2" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "the Sun's Gone Dim and the Sky's turned Black ~";
        const int argc = 4;
        const char* a = "/usr/local/bin/foo";
        const char* b = "die";
        const char* c = "--final-words";
        const char* d = finalWords.c_str();

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b),
                const_cast<char*>(c),
                const_cast<char*>(d)
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        REQUIRE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& die = std::get<DieCommand>( parsed.command );
        CHECK( die.finalWords );
        CHECK( finalWords == die.finalWords );
        CHECK( finalWords == die.finalWords.value() );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWordsDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == DIE_RESULT );
    }


    TEST_CASE( "FooExample3" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string greeting = "crimey";
        const int argc = 6;
        const char* a = "/usr/local/bin/foo";
        const char* b = "greet";
        const char* c = "--g";
        const char* d = greeting.c_str();
        const char* e = "--times";
        const char* f = "1000";

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b),
                const_cast<char*>(c),
                const_cast<char*>(d),
                const_cast<char*>(e),
                const_cast<char*>(f)
        };

        const auto parsed = ParseArgs( argc, argv );
        REQUIRE( std::holds_alternative<GreetCommand>( parsed.command ) );
        CHECK_FALSE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& greet = std::get<GreetCommand>( parsed.command );
        CHECK( greeting == greet.greeting );
        CHECK( greet.times );
        CHECK( 1000 == greet.times );
        CHECK( 1000 == greet.times.value() );
        CHECK( 1 == greet.timesDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == GREET_RESULT );
    }


    TEST_CASE( "FooExample4" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const int argc = 2;
        const char* a = "/usr/local/bin/foo";
        const char* b = "die";

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b)
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        REQUIRE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& die = std::get<DieCommand>( parsed.command );
        CHECK_FALSE( die.finalWords );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWords );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWords.value() );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWordsDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == DIE_RESULT );
    }


    TEST_CASE( "FooExample5" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "bar";
        const int argc = 4;
        const char* a = "/usr/local/bin/foo";
        const char* b = "die";
        const char* c = "-f";
        const char* d = finalWords.c_str();

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b),
                const_cast<char*>(c),
                const_cast<char*>(d),
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        REQUIRE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& die = std::get<DieCommand>( parsed.command );
        CHECK( die.finalWords );
        CHECK( finalWords == die.finalWords );
        CHECK( finalWords == die.finalWords.value() );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWordsDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == DIE_RESULT );
    }


    TEST_CASE( "FooExample6" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "bar";
        const int argc = 4;
        const char* a = "/usr/local/bin/foo";
        const char* b = "die";
        const char* c = "-f";
        const char* d = finalWords.c_str();

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b),
                const_cast<char*>(c),
                const_cast<char*>(d),
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        REQUIRE( std::holds_alternative<DieCommand>( parsed.command ) );
        const auto& die = std::get<DieCommand>( parsed.command );
        CHECK( die.finalWords );
        CHECK( finalWords == die.finalWords );
        CHECK( finalWords == die.finalWords.value() );
        CHECK( DIE_COMMAND_DEFAULT_FINAL_WORDS == die.finalWordsDefault );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == DIE_RESULT );
    }


    TEST_CASE( "FooExample7" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "bar";
        const int argc = 1;
        const char* a = "/usr/local/bin/foo";

        char* argv[] = {
                const_cast<char*>(a)
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        CHECK_FALSE( std::holds_alternative<DieCommand>( parsed.command ) );
        CHECK_FALSE( parsed.errors.empty() );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == EXIT_ERROR );
        const auto o = stdout.str();
        const auto e = stderr.str();
        CHECK_FALSE( o.empty() );
        CHECK_FALSE( e.empty() );
    }


    TEST_CASE( "FooExample8" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "bar";
        const int argc = 2;
        const char* a = "/usr/local/bin/foo";
        const char* b = "--help";

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b)
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        CHECK_FALSE( std::holds_alternative<DieCommand>( parsed.command ) );
        CHECK_FALSE( parsed.errors.empty() );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == EXIT_OK );
        const auto o = stdout.str();
        const auto e = stderr.str();
        CHECK_FALSE( o.empty() );
        CHECK( e.empty() );
    }


    TEST_CASE( "FooExample9" )
    {
        std::stringstream stdout;
        std::stringstream stderr;
        const std::string finalWords = "bar";
        const int argc = 3;
        const char* a = "/usr/local/bin/foo";
        const char* b = "--help";

        char* argv[] = {
                const_cast<char*>(a),
                const_cast<char*>(b)
        };

        const auto parsed = ParseArgs( argc, argv );
        CHECK_FALSE( std::holds_alternative<GreetCommand>( parsed.command ) );
        CHECK_FALSE( std::holds_alternative<DieCommand>( parsed.command ) );
        CHECK_FALSE( parsed.errors.empty() );
        const auto result = Dispatch( parsed, stdout, stderr );
        CHECK( result == EXIT_OK );
        const auto o = stdout.str();
        const auto e = stderr.str();
        CHECK_FALSE( o.empty() );
        CHECK( e.empty() );
    }
}