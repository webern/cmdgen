// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <string>

namespace cmdgen
{
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
}
