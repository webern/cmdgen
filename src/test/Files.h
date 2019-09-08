// cmdgen by (c) Matthew James Briggs

#include "Path.h"
#include "catch.hpp"

namespace cmdgen
{
    inline std::string
    GIT_EXAMPLE()
    {
        return filepath( "git-example.xml" );
    }


    inline std::string
    FOO_EXAMPLE()
    {
        return filepath( "foo-example.xml" );
    }
}
