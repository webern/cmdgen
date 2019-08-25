// cppcmd (c) MatthewJamesBriggs

#pragma once

#include "cppcmd/RawArgs.h"
#include "cppcmd/Config.h"
#include "ParsedArgs.h"

namespace cppcmd
{
    const ParsedArgs
    parse( const Config& inConfig, const RawArgs& inRawArgs );
}
