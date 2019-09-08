// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <vector>
#include "Command.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    void
    ParseCommands(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end,
            std::vector<Command>& ioCommands
    );
}
