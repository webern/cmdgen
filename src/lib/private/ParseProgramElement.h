// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <vector>
#include "ProgramElement.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    ProgramElement
    ParseProgramElement(
            ezxml::XElementIterator iter,
            ezxml::XElementIterator end
    );
}
