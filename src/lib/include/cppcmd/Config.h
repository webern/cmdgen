// cppcmd (c) MatthewJamesBriggs

#pragma once

#include "cppcmd/Command.h"
#include <string>
#include <vector>

namespace cppcmd
{
    class Config
    {
    public:
        Config( std::string inAppName, std::string inAppDescription );
        [[nodiscard]] const std::string& getAppName() const;
        [[nodiscard]] const std::string& getAppDescription() const;

    private:
        const std::string myAppName;
        const std::string myAppDescription;
    };
}
