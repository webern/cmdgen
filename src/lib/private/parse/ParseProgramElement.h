// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <vector>
#include "data/Program.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    Program
    ParseProgramElement(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end
    );
}
