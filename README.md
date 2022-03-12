# Chocoholics Anonymous - term project

This is the repository for the Chocoholics Anonymous simulator for CS 300 (Winter 2022) group 3

* [Requirements document](https://docs.google.com/document/d/1RpVwt8fgzjwomc8ez05ZhU8L0VpNRmZc)
* [Design document](https://docs.google.com/document/d/1ZyBydwm7Jk_bdQa6aKjwHlE4gDOu9ixqZocWLCAENp4)
* [Test plan](https://docs.google.com/document/d/17-V0Ud7mVgM7kHb84YpJ6ufTIso4oXXkr0TAZcUB-dg)

## Build instructions

To build, run `make` in the project root. sqlite3 must be installed and in the linker path.
If the build is succesful, a binary called choc-an will be generated in the project root directory.

To run tests, run `make test`

## Usage

There are four modes of operation, decided by a single argument passed on the command line:

```
./choc-an provider|manager|backend|create-data

provider:    Start provider terminal
manager:     Start manager terminal
backend:     Start backend (generates email reports and exits)
create-data: Creates sample data for testing purposes
```
