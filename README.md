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

Or if you are using gcc replace `clang` with `gcc`. It's also recommended to use the -Oz (Clang) or -Os (GCC) flags to optimize for size as Cassandra is meant to run in constrained environments. Completely optional. Stripping (`strip`) usually reduces the binary more than size optimization flags.

Or just run `make` because I added a Makefile now.

The Makefile defaults to Clang, so make sure to pass CC=gcc when running make if you are using GCC. The Makefile uses -Oz flag by default. oh shit fuck. i forgot something. -Oz is hardcoded but only clang uses it. ill fix the Makefile idk


## TODO
Improve Makefile

Use 1 centralized repo URL

Add a cpm list -i command that lists installed packages

Fill in the blanks for the other empty files like remove.c and update.c
