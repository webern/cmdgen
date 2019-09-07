// cmdgen by (c) Matthew James Briggs

#include <iostream>
#include "cmdgen/Command.h"
#include "cmdgen/MultiCommand.h"
#include "cmdgen/NamedLeafCommand.h"
#include "cmdgen/Config.h"


int
main( int argc, char* argv[] )
{
    using namespace cmdgen;
    CommandPtr echo =
            CommandPtr{ new NamedLeafCommand{
                    "foo",
                    "the foo command does blah blah",
                    ArgSpecifications{}
            } };

    Config config = Config{
            "cmdgen_example",
            "an example program",
            std::move( Commands{ std::move( echo ) } ) };

    std::cout << "cmdgen main" << std::endl;
}
