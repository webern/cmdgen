// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>
#include <optional>
#include <variant>
#include <vector>
#include <iostream>

namespace foo_example
{
    constexpr const int EXIT_OK = 0;
    constexpr const int EXIT_ERROR = 1;
    constexpr const int EXIT_EXCEPTION = 2;
    constexpr const char* const DIE_COMMAND_DEFAULT_FINAL_WORDS = "ach du lieber";
    constexpr const int GREET_COMMAND_DEFAULT_TIMES = 1;

    struct GreetCommand
    {
        std::string greeting;
        std::optional<int> times;
        int timesDefault = GREET_COMMAND_DEFAULT_TIMES;
    };

    struct DieCommand
    {
        std::optional<std::string> finalWords;
        std::string finalWordsDefault = DIE_COMMAND_DEFAULT_FINAL_WORDS;
    };

    enum class DispatchType
    {
        PARSE_ERROR,
        HELP,
        GREET_COMMAND,
        GREET_COMMAND_HELP,
        DIE_COMMAND,
        DIE_COMMAND_HELP
    };

    struct CommandLine
    {
        DispatchType type;
        std::variant<GreetCommand, DieCommand> command;
        std::vector<std::string> errors;
    };

    int
    runGreetCommand( const GreetCommand& greetCommand );

    int
    runDieCommand( const DieCommand& greetCommand );


    inline std::vector<std::string>
    FriendlyArgs( int argc, char* argv[] )
    {
        std::vector<std::string> friendlyArgs( argc );
        for( int i = 0; i < argc; ++i )
        {
            friendlyArgs.emplace_back( std::string{ argv[i] } );
        }
        return friendlyArgs;
    };


    inline CommandLine
    ParseArgs( const std::vector<std::string>& inArgs )
    {
        return CommandLine{};
    }


    inline CommandLine
    ParseArgs( int argc, char* argv[] )
    {
        return ParseArgs( FriendlyArgs( argc, argv ) );
    }


    int
    Dispatch( const CommandLine& commandLine, std::ostream& stdout, std::ostream& stderr )
    {
        switch( commandLine.type )
        {
            case DispatchType::PARSE_ERROR:
            {
                // TODO - print error
                // TODO - print usage
                return 1;
            }
            case DispatchType::HELP:
            {
                // TODO - print help
                return EXIT_OK;
            }
            case DispatchType::GREET_COMMAND:
            {
                return runGreetCommand( std::get<GreetCommand>( commandLine.command ) );
            }
            case DispatchType::GREET_COMMAND_HELP:
            {
                // TODO - print greet help
                return EXIT_OK;
            }
            case DispatchType::DIE_COMMAND:
            {
                return runDieCommand( std::get<DieCommand>( commandLine.command ) );
            }
            case DispatchType::DIE_COMMAND_HELP:
            {
                // TODO - print die command help
                return EXIT_OK;
            }
            default:
            {
                // TODO - print a bug error
                return EXIT_ERROR;
            }
        }
    }


    int
    DoMain( int argc, char* argv[] )
    {
        const auto commandLine = ParseArgs( argc, argv );
        return Dispatch( commandLine, std::cout, std::cerr );
    }
}
