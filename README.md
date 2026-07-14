# Cassandra Package Manager - CPM

This is a package manager written in C and specifically
tailored to the Cassandra386 Linux system am working on
alongside it.

## Features
CPM implements the following 6 basic functions:
    Install
    Remove
    Update
    Upgrade
    Search
    Help

## Building from source
Currently, only 3 files have code in them. Therefore, there is no need to use Make.

### Prerequisites
Make sure to have Clang or GCC installed.

In the root of the project run;

```bash
clang src/cpm.c src/help.c src/install.c src/update.c src/list.c -Iinclude -o cpm
```
