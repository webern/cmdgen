// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include "data/Config.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    Config
    ParseConfigRoot( const ezxml::XElementPtr& root );
}
