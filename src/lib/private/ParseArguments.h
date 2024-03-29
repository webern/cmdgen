// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <vector>
#include "Argument.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    void
    ParseArguments(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end,
            std::vector<Argument>& ioArguments
    );
}
