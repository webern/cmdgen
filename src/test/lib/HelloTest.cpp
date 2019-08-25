// cppcmd by (c) Matthew James Briggs

#include "cppcmd/Hello.h"
#include "../catch.hpp"

namespace cppcmd
{
  TEST_CASE( "Factorials are computed" ) {
    const auto hello = Hello{};
    CHECK( 5 == hello.getFive() );
  }
}
