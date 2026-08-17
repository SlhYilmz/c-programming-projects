# data-serialization
A project involving data serialization and deserialization in C programming.

## Project layout

- `inc/` contains the public API and logbook data types.
- `src/` contains implementations and private headers.
- `main.c` is the example application and includes only `inc/logbook.h`.
- `build/obj/` contains generated object and dependency files.
- `build/bin/` contains the executable.

## Build

Run `make` to build, `make run` to build and execute, or `make clean` to remove
the entire generated `build/` directory. Source files added to `src/` are
discovered automatically.
