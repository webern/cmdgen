// cppcmd by (c) Matthew James Briggs

#include <iostream>
#include "cppcmd/Command.h"
#include "cppcmd/MultiCommand.h"
#include "cppcmd/NamedLeafCommand.h"
#include "cppcmd/Config.h"


int
main( int argc, char* argv[] )
{
    using namespace cppcmd;
    CommandPtr echo =
            CommandPtr{ new NamedLeafCommand{
                    "foo",
                    "the foo command does blah blah",
                    ArgSpecifications{}
            } };

    Config config = Config{
            "cppcmd_example",
            "an example program",
            std::move( Commands{ std::move( echo ) } ) };

    std::cout << "cppcmd main" << std::endl;
}
