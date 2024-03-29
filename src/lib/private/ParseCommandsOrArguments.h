// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include <vector>
#include "Argument.h"
#include "Command.h"
#include "ezxml/ezxml.h"

namespace cmdgen
{
    void
    ParseCommandsOrArguments(
            const ezxml::XElementIterator& iter,
            std::vector<Command>& ioCommands,
            std::vector<Argument>& ioArguments
    );
}
