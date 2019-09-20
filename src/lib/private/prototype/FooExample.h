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

    struct Argument;
    struct CmdGen;
    struct Command;
    struct Program;
    enum class Type;

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
    ParseArgs( const std::vector<std::string>& inArgs, const CmdGen& cmdGen )
    {
        return CommandLine{};
    }


    struct Argument
    {
        bool unlabeled = false;
        std::string name;
        std::string shorthand;
        std::string description;
        int minOccurs = -1;
        int maxOccurs = -1;
        Type type;
        std::string defaultValue;
    };

    struct Command
    {
        std::string name;
        std::string description;
        std::vector<std::string> examples;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };

    struct Program
    {
        std::string name;
        std::string description;
        std::vector<std::string> examples;
    };

    struct CmdGen
    {
        Program program;
        std::vector<Command> commands;
        std::vector<Argument> arguments;
    };

    enum class Type
    {
        ERROR,
        STRING,
        INT,
        INT64
    };

    static constexpr const char* const STRING_STR = "string";
    static constexpr const char* const INT_STR = "int";
    static constexpr const char* const INT64_STR = "int64";


    inline Type
    ParseType( const std::string& inString )
    {
        if( inString == std::string{ STRING_STR } )
        {
            return Type::STRING;
        }
        else if( inString == std::string{ INT_STR } )
        {
            return Type::INT;
        }
        else if( inString == std::string{ INT64_STR } )
        {
            return Type::INT64;
        }

        return Type::ERROR;
    }


    inline std::string
    ToString( Type t )
    {
        switch( t )
        {
            case Type::ERROR: return "!! ERROR !!";
            case Type::STRING: return STRING_STR;
            case Type::INT: return INT_STR;
            case Type::INT64: return INT64_STR;
            default: return "!! BAD TYPE VALUE !!";
        }
    }


    inline CmdGen
    createStructure();


    inline CommandLine
    ParseArgs( int argc, char* argv[] )
    {
        return ParseArgs( FriendlyArgs( argc, argv ), createStructure() );
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


    inline CmdGen
    createStructure()
    {
        // greet command

        Argument greeting;
        greeting.name = "greeting";
        greeting.unlabeled = false;
        greeting.shorthand = "g";
        greeting.description = "The greeting to print to the console";
        greeting.minOccurs = 1;
        greeting.maxOccurs = 1;
        greeting.defaultValue = "";
        greeting.type = Type::STRING;

        Argument times;
        greeting.name = "times";
        greeting.unlabeled = false;
        greeting.shorthand = "t";
        greeting.description = "The number of times to print the greeting to the console.";
        greeting.minOccurs = 0;
        greeting.maxOccurs = 1;
        greeting.type = Type::INT;

        Command greet;
        greet.name = "greet";
        greet.description = "Prints a greeting to the console one or more times.";
        greet.arguments.emplace_back( std::move( greeting ) );
        greet.arguments.emplace_back( std::move( times ) );


        // die command

        Argument finalWords;
        finalWords.name = "final-words";
        finalWords.description = ">Prints final words to the console.";
        finalWords.unlabeled = false;
        finalWords.shorthand = "f";
        finalWords.minOccurs = 0;
        finalWords.maxOccurs = 1;
        finalWords.defaultValue = "ach du lieber";
        finalWords.type = Type::STRING;

        Command die;
        die.name = "die";
        die.description = "Says one last thing.";
        die.arguments.emplace_back( std::move( finalWords ) );

        // cmd

        CmdGen cmd;
        cmd.program.name = "foo";
        cmd.program.description = "A program that greets or dies.";
        cmd.program.examples.emplace_back( "foo greet --greeting \"hello world\"" );
        cmd.program.examples.emplace_back( "foo die --final-words \"goodbye world\"" );
        cmd.program.examples.emplace_back( "foo greet -g crimey --times 1000" );
        cmd.program.examples.emplace_back( "foo die" );
        cmd.program.examples.emplace_back( "foo die -f bar" );
        cmd.commands.emplace_back( std::move( greet ) );
        cmd.commands.emplace_back( std::move( die ) );
        return cmd;
    }
}

/*
 <?xml version="1.0"?>
<cmdgen>
    <program>
      <name>foo</name>
      <description>A program that greets or dies.</description>
      <examples>
        <example>foo greet --greeting "hello world"</example>
        <example>foo die --final-words "goodbye world"</example>
        <example>foo greet -g crimey --times 1000</example>
        <example>foo die</example>
        <example>foo die -f bar</example>
    </examples>
    </program>
    <settings/>
    <commands>
        <command>
            <name>greet</name>
            <description>Prints a greeting to the console one or more times.</description>
            <arguments>
                <argument>
                    <name>greeting</name>
                    <shorthand>g</shorthand>
                    <description>The greeting to print to the console.</description>
                    <min-occurs>1</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>string</type>
                    <default/>
                </argument>
                <argument>
                    <name>times</name>
                    <shorthand>t</shorthand>
                    <description>The number of times to print the greeting to the console.</description>
                    <min-occurs>0</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>int</type>
                    <default>1</default>
                </argument>
            </arguments>
        </command>
        <command>
            <name>die</name>
            <arguments>
                <argument>
                    <name>final-words</name>
                    <description>Prints final words to the console.</description>
                    <shorthand>f</shorthand>
                    <min-occurs>0</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>string</type>
                    <default>ach du lieber</default>
                </argument>
            </arguments>
        </command>
    </commands>
</cmdgen>
 */
