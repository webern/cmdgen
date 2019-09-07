// cmdgen (c) MatthewJamesBriggs

#pragma once

#include "cmdgen/Command.h"
#include <string>
#include <vector>

namespace cmdgen
{
    class RawArgs
    {
    public:
        RawArgs( int argc, char** argv );
        explicit RawArgs( std::vector<std::string> inArgs );
        ~RawArgs();

        [[nodiscard]] const std::vector<std::string>& getArgs() const;
        [[nodiscard]] int getArgC() const;
        [[nodiscard]] char** getArgV() const; // caution: do not mutate

    private:
        int myArgC;
        char** myArgV;
        bool myIsArgVOwned;
        std::vector<std::string> myArgs;
    };
}
