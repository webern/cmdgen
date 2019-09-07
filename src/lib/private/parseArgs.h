// cmdgen (c) MatthewJamesBriggs

#pragma once

#include "cmdgen/RawArgs.h"
#include "cmdgen/ParsedArgs.h"

namespace cmdgen
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