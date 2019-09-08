// cmdgen by (c) Matthew James Briggs

#include "parse/ParseConfigRoot.h"
#include "Path.h"
#include "catch.hpp"
#include "ezxml/ezxml.h"
#include "Files.h"

namespace
{
    cmdgen::Config
    load( const std::string& inFilename )
    {
        auto xdoc = ezxml::XFactory::makeXDoc();
        xdoc->loadFile( inFilename );
        const auto root = xdoc->getRoot();
        const auto config = cmdgen::ParseConfigRoot( root );
        return config;
    }
}

namespace cmdgen
{
    TEST_CASE( "ParseConfigRoot-git-example" )
    {
        const auto config = load( GIT_EXAMPLE() );
        CHECK( "gitt" == config.program.name );
        CHECK( "Some program kind of familiar." == config.program.description );
        CHECK( 0 == config.arguments.size() );
        REQUIRE( 1 == config.commands.size() );
        const auto& remote = config.commands.at( 0 );
        CHECK( "remote" == remote.name );
        CHECK( 0 == remote.arguments.size() );
        REQUIRE( 2 == remote.commands.size() );

        const auto& add = remote.commands.at( 0 );
        CHECK( "add" == add.name );
        CHECK( 0 == add.commands.size() );
        REQUIRE( 2 == add.arguments.size() );

        const auto& remove = remote.commands.at( 1 );
        CHECK( "remove" == remove.name );
        CHECK( 0 == remove.commands.size() );
        REQUIRE( 1 == remove.arguments.size() );
    }


    TEST_CASE( "ParseConfigRoot-foo-example" )
    {
        const auto config = load( FOO_EXAMPLE() );
        CHECK( "foo" == config.program.name );
        CHECK( "A program that greets or dies." == config.program.description );
        CHECK( config.arguments.empty() );
        REQUIRE( 2 == config.commands.size() );

        // greet command
        const auto& greet = config.commands.at( 0 );

        CHECK( "greet" == greet.name );
        CHECK( greet.commands.empty() );
        REQUIRE( 2 == greet.arguments.size() );

        // greet command arguments
        const auto greetArg0 = greet.arguments.at( 0 );
        CHECK( "greeting" == greetArg0.name );
        CHECK( "g" == greetArg0.shorthand );
        CHECK( "The greeting to print to the console." == greetArg0.description );
        CHECK( 1 == greetArg0.minOccurs );
        CHECK( 1 == greetArg0.maxOccurs );
        CHECK( greetArg0.defaultValue.empty() );
        CHECK( Type::STRING == greetArg0.type );

        const auto greetArg1 = greet.arguments.at( 1 );
        CHECK( "times" == greetArg1.name );
        CHECK( "t" == greetArg1.shorthand );
        CHECK( "The number of times to print the greeting to the console." == greetArg1.description );
        CHECK( 0 == greetArg1.minOccurs );
        CHECK( 1 == greetArg1.maxOccurs );
        CHECK( "1" == greetArg1.defaultValue );
        CHECK( Type::INT == greetArg1.type );

        // die command
        const auto& die = config.commands.at( 1 );

        CHECK( "die" == die.name );
        CHECK( die.commands.empty() );
        REQUIRE( 1 == die.arguments.size() );

        // die command arguments
        const auto dieArg0 = die.arguments.at( 0 );
        CHECK( "final-words" == dieArg0.name );
        CHECK( "f" == dieArg0.shorthand );
        CHECK( "Prints final words to the console." == dieArg0.description );
        CHECK( 0 == dieArg0.minOccurs );
        CHECK( 1 == dieArg0.maxOccurs );
        CHECK( "ach du lieber" == dieArg0.defaultValue );
        CHECK( Type::STRING == dieArg0.type );

    }
}
