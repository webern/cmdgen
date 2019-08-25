// cppcmd (c) MatthewJamesBriggs

#pragma once

#include "Command.h"
#include "CommandsOrArgs.h"
#include <string>
#include <vector>

namespace cppcmd
{
    class RawArgs
    {
    public:
        RawArgs( int argc, char** argv );
        explicit RawArgs( std::vector<std::string> inArgs );

        [[nodiscard]] std::vector<std::string> getArgs() const;
        [[nodiscard]] int getArgC() const;
        char** getArgV();

    private:
        int myArgC;
        char** myArgV;
        std::vector<std::string> myArgs;
    };
}
