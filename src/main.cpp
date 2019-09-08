// cmdgen by (c) Matthew James Briggs

#include <iostream>
#include "cmdgen/Placeholder.h"
#include "ezxml/ezxml.h"


int
main( int argc, char* argv[] )
{
    using namespace cmdgen;
    Placeholder::print();

    if( argc != 3 || std::string{ argv[1] } != "-i" )
    {
        std::cout << "instant death" << std::endl;
        return 1;
    }

    const std::string input{ argv[2] };
    std::cout << "parsing " << input << std::endl;
}
