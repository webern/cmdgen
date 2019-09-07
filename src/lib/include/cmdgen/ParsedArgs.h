// cmdgen (c) MatthewJamesBriggs

#pragma once

#include <unordered_map>
#include "cmdgen/Typedef.h"
#include "cmdgen/ArgVal.h"
#include "cmdgen/Config.h"
#include "cmdgen/Error.h"

namespace cmdgen
{

    class ParsedArgs
    {
    public:
        explicit ParsedArgs( const ArgSpecifications& inArgSpecifications );
        [[nodiscard]] bool getIsPresent( const std::string& inFullName ) const;
        [[nodiscard]] ArgVal getArgVal( const std::string& inFullName ) const;
        void setArgVal( const ArgVal& inArgVal );
        void addError( Error inError );
        [[nodiscard]] const Errors& getErrors() const;
        [[nodiscard]] bool getIsError() const;
        [[nodiscard]] bool getIsHelp() const;
        void setArgZero( std::string inArgZero );
        [[nodiscard]] const std::string& getArgZero() const;

    private:
        using ArgMap = std::unordered_map<std::string, ArgVal>;
        using ArgMapPair = std::pair<std::string, ArgVal>;
        ArgMap myArgMap;
        Errors myErrors;
        std::string myArgZero;

    private:
        static ArgMap createArgMap( const ArgSpecifications& inArgSpecifications );
    };
}
