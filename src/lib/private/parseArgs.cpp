// cmdgen (c) MatthewJamesBriggs

#include <utility>
#include <sstream>
#include <cmdgen/RawArgs.h>
#include "cmdgen/ParsedArgs.h"
#include "parseArgs.h"

namespace cmdgen
{

    enum class POS
    {
        P_FLAG,
        P_VALUE
    };

    static constexpr const POS FLAG = POS::P_FLAG;
    static constexpr const POS VALUE = POS::P_VALUE;

    struct State
    {
        const ArgSpecifications& specs;
        const RawArgs& rawArgs;
        const Strings raw;
        int index;
        Strings::const_iterator iter;
        POS pos;
        ArgSpecifications::const_iterator spec;
        ArgSpecifications::const_iterator specEnd;
        String value;
        ParsedArgs parsed;


        State( const ArgSpecifications& inArgSpecifications, const RawArgs& inRawArgs )
                : specs{ inArgSpecifications },
                  rawArgs{ inRawArgs },
                  raw{ inRawArgs.getArgs() },
                  index{ 0 },
                  iter{ this->raw.cbegin() },
                  pos{ VALUE }, // we start on VALUE because arg zero is a value.
                  spec{ this->specs.cend() },
                  specEnd{ this->specs.cend() },
                  value{},
                  parsed{ this->specs }
        {

        }


        void next()
        {
            const bool stayOnPosAfterFlag = pos == FLAG && spec != specEnd && spec->getIsFlag();
            const bool switchFromFlagToVal = pos == FLAG && !stayOnPosAfterFlag;
            const bool switchFromValToFlag = pos == VALUE;
            const bool doReset = stayOnPosAfterFlag || switchFromValToFlag;

            if( switchFromFlagToVal )
            {
                pos = VALUE;
            }
            else if( switchFromValToFlag )
            {
                pos = FLAG;
            }

            if( doReset )
            {
                reset();
            }

            ++index;
            ++iter;
        }


        void reset()
        {
            value = "";
            spec = specEnd;
        }
    };

    bool
    handleFlag( State& s );

    bool
    handleValue( State& s );


    ParsedArgs
    parseArgs( const ArgSpecifications& inArgSpecifications, const RawArgs& inRawArgs )
    {
        State s{ inArgSpecifications, inRawArgs };
        for( ; s.iter != s.raw.cend(); s.next() )
        {
            if( s.index == 0 )
            {
                s.parsed.setArgZero( *s.iter );
                continue;
            }

            if( s.pos == FLAG )
            {
                if( !handleFlag( s ) )
                {
                    return s.parsed;
                }
            }
            else
            {
                if( !handleValue( s ) )
                {
                    return s.parsed;
                }
            }
        }

        return s.parsed;
    }


    bool
    isFlag( const std::string& str )
    {
        if( str.empty() )
        {
            return false;
        }

        return str.at( 0 ) == '-';
    }


    std::string
    getFlagName( const std::string& str )
    {
        if( str.size() < 2 )
        {
            return "";
        }
        else if( str.size() == 2 )
        {
            if( str == "--" )
            {
                return "";
            }

            return std::string{ *str.crbegin() };
        }
        else if( str.at( 0 ) != '-' )
        {
            return "";
        }

        std::stringstream ss;
        int index = 0;
        for( auto iter = str.cbegin(); iter != str.cend(); ++iter, ++index )
        {
            if( index <= 1 && *iter == '-' )
            {
                continue;
            }
            else if( std::isspace( *iter ) )
            {
                return ss.str();
            }
            else
            {
                ss << std::string{ *iter };
            }
        }

        return ss.str();
    }


    bool
    isValidFlag( const std::string& flagName, const ArgSpecifications& inArgSpecifications )
    {
        for( const auto& spec : inArgSpecifications )
        {
            if( flagName == spec.getFullName() )
            {
                return true;
            }
            else if( flagName == std::string{ spec.getShortName() } )
            {
                return true;
            }
        }

        return false;
    }


    Error
    createNotFlagError( int inIndex, std::string inRawArg )
    {
        Error e;
        e.rawArgsIndex = inIndex;
        e.rawArgsValue = std::move( inRawArg );
        e.message = "A flag or switch name was expected but none was found.";
        return e;
    }


    Error
    createInvalidSwitchError( int inIndex, std::string inRawArg, const std::string& inFlagName )
    {
        Error e;
        e.rawArgsIndex = inIndex;
        e.rawArgsValue = std::move( inRawArg );
        std::stringstream message;
        message << "A flag named '" << inFlagName << "' was encountered.";
        e.message = message.str();
        return e;
    }


    Error
    createSpecEndError( int inIndex, std::string inRawArg )
    {
        Error e;
        e.rawArgsIndex = inIndex;
        e.rawArgsValue = std::move( inRawArg );
        e.message = "A bug occurred during parsing, s.spec == s.specEnd";
        return e;
    }


    ArgSpecifications::const_iterator
    findArgSpec( const std::string& inFlagName, const ArgSpecifications& inArgSpecifications )
    {
        for( auto spec = inArgSpecifications.cbegin(); spec != inArgSpecifications.cend(); ++spec )
        {
            if( inFlagName == spec->getFullName() )
            {
                return spec;
            }
            else if( inFlagName == std::string{ spec->getShortName() } )
            {
                return spec;
            }
        }

        return inArgSpecifications.cend();
    }


    bool
    handleFlag( State& s )
    {
        if( !isFlag( *s.iter ) )
        {
            s.parsed.addError( createNotFlagError( s.index, *s.iter ) );
            s.spec = s.specEnd;
            return false;
        }

        const auto flagName = getFlagName( *s.iter );
        const auto argSpec = findArgSpec( flagName, s.specs );

        if( argSpec == s.specEnd )
        {
            s.parsed.addError( createInvalidSwitchError( s.index, *s.iter, flagName ) );
            s.spec = s.specEnd;
            return false;
        }

        s.spec = argSpec;

        if( s.spec->getIsFlag() )
        {
            const auto currentVal = s.parsed.getArgVal( s.spec->getFullName() );
            s.parsed.setArgVal( ArgVal{ true, s.spec->getFullName(), Strings{} } );
        }

        return true;
    }


    bool
    handleValue( State& s )
    {
        if( s.spec == s.specEnd )
        {
            throw std::runtime_error{ "A bug occurred during parsing spec == specEnd " };
        }

        const auto& spec = *s.spec;
        const auto currentVal = s.parsed.getArgVal( spec.getFullName() );
        if( spec.getMaxCount() > 0 && currentVal.getValueCount() >= spec.getMaxCount() )
        {
            Error e;
            e.rawArgsIndex = s.index;
            e.rawArgsValue = *s.iter;
            std::stringstream message;
            message << "More than " << spec.getMaxCount() << " occurrence"
                    << ( spec.getMaxCount() > 1 ? "s" : "" )
                    << " of the " << spec.getFullName()
                    << " option were encountered. Only " << spec.getMaxCount() << " allowed.";
            e.message = message.str();
            s.parsed.addError( e );
            return false;
        }
        else if( spec.getIsFlag() )
        {
            Error e;
            e.rawArgsIndex = s.index;
            e.rawArgsValue = *s.iter;
            std::stringstream message;
            message << "Option '" << spec.getFullName() << "' is a flag. No value can be assigned to it"
                    << " but value '" << *s.iter << "' was encountered.";
            e.message = message.str();
            s.parsed.addError( e );
            return false;
        }

        Strings vals = currentVal.getAllValues();
        vals.push_back( *s.iter );
        s.parsed.setArgVal( ArgVal{ true, currentVal.getFullName(), vals } );
        return true;
    }
}