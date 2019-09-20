// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include "data/CmdGen.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    CmdGen
    ParseConfigRoot( const ezxml::XElementPtr& root );
}
