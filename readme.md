cmdgen
======

[![CircleCI](https://circleci.com/gh/webern/cmdgen/tree/master.svg?style=svg)](https://circleci.com/gh/webern/cmdgen/tree/master)
[![CircleCI](https://circleci.com/gh/webern/cmdgen/tree/develop.svg?style=svg)](https://circleci.com/gh/webern/cmdgen/tree/develop)

cmdgen is a command line program which reads a definition of commands and arguments, provided by an xml file, and generates the necessary code to stub out CLI program that takes those commands and arguments.

Commands form a tree-like structure, and should be familiar to most from git. For example this:

```
git remote add origin https://github.com/webern/cmdgen.git
^   ^^^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
program   commands                argument(s)
```

This can be specified and generated with xml that looks like this:

```xml
<cmdgen>
  <program>git</program>
  <commands>
    <command>
      <name>remote</name>
      <commands>
        <name>origin</name>
        <arguments>
          <unnamed>
            <min-occurs>1</min-occurs>
            <max-occurs>1</max-occurs>
            <type>string</type>
          </unnamed>
        </arguments>
      </commands>
    </command>
  </commands>
</cmdgen>
```

You can then stub out the program with `cmdgen -i config.xml`
