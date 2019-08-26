// cppcmd (c) MatthewJamesBriggs

#pragma once

#include "cppcmd/RawArgs.h"
#include "cppcmd/ParsedArgs.h"

namespace cppcmd
{
    ParsedArgs
    parseArgs( const ArgSpecifications& inArgSpecifications, const RawArgs& inRawArgs );

    bool
    isFlag( const std::string& str );

    std::string
    getFlagName( const std::string& str );

    Error
    createNotFlagError( int inIndex, std::string inRawArg );

    Error
    createInvalidSwitchError( int inIndex, std::string inRawArg, const std::string& inFlagName );

}