// cmdgen (c) MatthewJamesBriggs

#pragma once

#include "cmdgen/RawArgs.h"
#include "cmdgen/Config.h"
#include "ParsedArgs.h"

namespace cmdgen
{
    const ParsedArgs
    parse( const Config& inConfig, const RawArgs& inRawArgs );
}
