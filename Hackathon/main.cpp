#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include <unordered_map>
#include "include/People.h"
#include "include/Person.h"
#include "include/Relation.h"
#include "include/Parser.h"

int main(int argc, char *argv[])
{
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

    std::list<Person>* people = parse(fd);


    for(int i = 0; i < people.getSize(); ++i)
        printf("%s\n", people.getPerson(i).getID);



    return 0;
}
