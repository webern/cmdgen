// cmdgen by (c) Matthew James Briggs

#include "ParseConfigRoot.h"
#include "Path.h"
#include "catch.hpp"
#include "ezxml/ezxml.h"
#include <iosfwd>

constexpr const char* const xml = R"(
<?xml version="1.0"?>
<cmdgen>
  <program>git</program>
  <commands>
    <command>
      <name>remote</name>
      <commands>
        <command>
          <name>add</name>
          <arguments>
            <unflagged>
              <name>remote-name</name>
              <min-occurs>1</min-occurs>
              <max-occurs>1</max-occurs>
              <type>string</type>
            </unflagged>
            <unflagged>
              <name>remote-uri</name>
              <min-occurs>1</min-occurs>
              <max-occurs>1</max-occurs>
              <type>string</type>
            </unflagged>
          </arguments>
        </command>
        <command>
          <name>remove</name>
          <arguments>
            <unflagged>
              <name>remote-name</name>
              <min-occurs>1</min-occurs>
              <max-occurs>1</max-occurs>
              <type>string</type>
            </unflagged>
          </arguments>
        </command>
      </commands>
    </command>
  </commands>
</cmdgen>
)";

namespace cmdgen
{
    TEST_CASE( "ParseConfigRootTest" )
    {
        auto xdoc = ezxml::XFactory::makeXDoc();
        std::istringstream iss{ xml };
        xdoc->loadStream( iss );
        const auto root = xdoc->getRoot();
        const auto config = ParseConfigRoot( root );

        CHECK( "git" == config.program );
        CHECK( 0 == config.arguments.size() );
        REQUIRE( 1 == config.commands.size() );
        const auto& remote = config.commands.at( 0 );
        CHECK( "remote" == remote.name );
        CHECK( 0 == remote.arguments.size() );
        REQUIRE( 2 == remote.commands.size() );

        const auto& add = remote.commands.at( 0 );
        CHECK( "add" == add.name );
        CHECK( 0 == add.commands.size() );
        REQUIRE( 2 == add.arguments.size() );

        const auto& remove = remote.commands.at( 1 );
        CHECK( "remove" == remove.name );
        CHECK( 0 == remove.commands.size() );
        REQUIRE( 1 == remove.arguments.size() );
    }
}
