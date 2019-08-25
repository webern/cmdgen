// cppcmd (c) MatthewJamesBriggs

#pragma once

#include <unordered_map>
#include "Typedef.h"
#include "ArgVal.h"
#include "Config.h"

namespace cppcmd
{

    class ParsedArgs
    {
    public:
        explicit ParsedArgs( const ArgSpecifications& inArgSpecifications );
        [[nodiscard]] bool getIsPresent( const std::string& inFullName ) const;
        [[nodiscard]] ArgVal getArgVal( const std::string& inFullName ) const;
        void setArgVal( const ArgVal& inArgVal );

    private:
        using ArgMap = std::unordered_map<std::string, ArgVal>;
        using ArgMapPair = std::pair<std::string, ArgVal>;
        ArgMap myArgMap;

    private:
        static ArgMap createArgMap( const ArgSpecifications& inArgSpecifications );
    };
}
