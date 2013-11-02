/*

Main.cpp

*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include <unordered_map>
#include "People.h"
#include "Person.h"
#include "Relation.h"
#include "Parser.h"

int main(int argc, char * argc[])
{
  // 1. Load the file into a file pointer.

  FILE *fd;

    //check if there is a specified input file
    if (argc < 1) {
        fprintf(stderr, "Define input file\n", argv[0]);
        return -1;
    }

    fd = fopen(argv[1], "r"); //open file stream

    //
    if (! fd) {
        fprintf(stderr, "Unable to open input file\n", argv[1]);
        return -1;
    }

  // 2. Use the parser class to create a list of people.

  std::list& referenceToPeopleList = Parser::parse(fd);

  // 3. Query the database.
}
