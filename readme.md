cmdgen
======

[![CircleCI](https://circleci.com/gh/webern/cmdgen/tree/master.svg?style=svg)](https://circleci.com/gh/webern/cmdgen/tree/master)
[![CircleCI](https://circleci.com/gh/webern/cmdgen/tree/develop.svg?style=svg)](https://circleci.com/gh/webern/cmdgen/tree/develop)

cmdgen is a command line program which reads a definition of commands and arguments, provided by an xml file, and generates the necessary code to stub out CLI program that takes those commands and arguments.

Imagine a `foo` program with two subcommands, `greet` and `die`. Valid command line executions of this program might look like this:

```
foo greet --greeting "hello world"
foo die --final-words "goodbye world"
foo greet -g crimey --times 1000
foo die
foo die --f "bar"
```

Another example:

```
gitt remote add origin https://github.com/webern/cmdgen.git
^    ^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
program   commands             unnamed arguments
```

This can be specified and generated with xml that looks like this:

```xml
<?xml version="1.0"?>
<!--
Examples:
gitt remote add origin https://whatever.git
gitt remote add upstream https://whatever.git
gitt remote remove origin
gitt remote remove upstream
-->
<cmdgen>
    <program>
      <name>gitt</name>
      <description>Some program kind of familiar.</description>
    </program>
    <settings/>
    <commands>
        <command>
            <name>remote</name>
            <commands>
                <command>
                    <name>add</name>
                    <arguments>
                        <unlabeled>
                            <name>remote-name</name>
                            <min-occurs>1</min-occurs>
                            <max-occurs>1</max-occurs>
                            <type>string</type>
                        </unlabeled>
                        <unlabeled>
                            <name>remote-uri</name>
                            <min-occurs>1</min-occurs>
                            <max-occurs>1</max-occurs>
                            <type>string</type>
                        </unlabeled>
                    </arguments>
                </command>
                <command>
                    <name>remove</name>
                    <arguments>
                        <unlabeled>
                            <name>remote-name</name>
                            <min-occurs>1</min-occurs>
                            <max-occurs>1</max-occurs>
                            <type>string</type>
                        </unlabeled>
                    </arguments>
                </command>
            </commands>
        </command>
    </commands>
</cmdgen>
```

## Code Generation

Using the `cmdgen` command-line program, you can stub out your `foo` or `gitt` program and `cmdgen` will generate the C++ code you need for parsing the command line arguments:

```
cmdgen --input myconfig.xml --lang C++
```
