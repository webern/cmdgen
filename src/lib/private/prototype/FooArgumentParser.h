// cmdgen by Matthew James Briggs, https://github.com/webern/cmdgen
#pragma once

#include "cmdgen/d
#include <string>
#include <optional>
#include <variant>
#include <vector>
#include <iostream>

namespace foo_example
{
    struct Program;


    inline void
    Structure()
    {
        return
    }
}
/*
 <?xml version="1.0"?>
<cmdgen>
    <program>
      <name>foo</name>
      <description>A program that greets or dies.</description>
      <examples>
        <example>foo greet --greeting "hello world"</example>
        <example>foo die --final-words "goodbye world"</example>
        <example>foo greet -g crimey --times 1000</example>
        <example>foo die</example>
        <example>foo die -f bar</example>
    </examples>
    </program>
    <settings/>
    <commands>
        <command>
            <name>greet</name>
            <description>Prints a greeting to the console one or more times.</description>
            <arguments>
                <argument>
                    <name>greeting</name>
                    <shorthand>g</shorthand>
                    <description>The greeting to print to the console.</description>
                    <min-occurs>1</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>string</type>
                    <default/>
                </argument>
                <argument>
                    <name>times</name>
                    <shorthand>t</shorthand>
                    <description>The number of times to print the greeting to the console.</description>
                    <min-occurs>0</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>int</type>
                    <default>1</default>
                </argument>
            </arguments>
        </command>
        <command>
            <name>die</name>
            <arguments>
                <argument>
                    <name>final-words</name>
                    <description>Prints final words to the console.</description>
                    <shorthand>f</shorthand>
                    <min-occurs>0</min-occurs>
                    <max-occurs>1</max-occurs>
                    <type>string</type>
                    <default>ach du lieber</default>
                </argument>
            </arguments>
        </command>
    </commands>
</cmdgen>
 */