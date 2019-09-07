// cmdgen by (c) Matthew James Briggs

#include "cmdgen/Placeholder.h"
#include "Path.h"
#include "catch.hpp"

// temporary, remove
#include "ezxml/ezxml.h"

namespace cmdgen
{
    TEST_CASE( "ParseGitExample" )
    {
        auto xdoc = ezxml::XFactory::makeXDoc();
        xdoc->loadFile( filepath( "git-example.xml" ) );
        std::cout << "whee" << std::endl;
        xdoc->saveStream( std::cout );
        const auto root = xdoc->getRoot();
    }
}

