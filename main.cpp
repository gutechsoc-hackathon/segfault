#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//parse the given file
static PersonsLL *parse(FILE *fd) {
    char bf[1024];
    PersonsLL *people;
    Person guy = (Person) malloc(sizeof(Person));
    int go = 0; //variable to determine whether we're adding relations or IDs

    while (fgets(bf, sizeof(bf), fd) != NULL) {

        //signify the start of adding relations
        if(strcmp(bf, "{")== 0){
            go = 1;
            continue;
        }

        //signify the end of adding relations. Add person to LL
        else if(strcmp(bf,"}") == 0) {
            go = 0;
            people.add(guy); //add to LL
            free(guy);
            guy = (Person)malloc(sizeof(Person));
            continue;
        }


        //if not adding relations, then we are adding IDs
        if(!go) {
            long long unsigned idi = strtoull(bf, NULL, 10);
            guy.setId(idi);
        }

        //if we are adding relations, split by space, send (type, id) to person class
        else {
            char *part;
            part = strtok(bf, " ");
            int type = atoi(part);
            long long unsigned idi = strtoull(strtok(NULL, "\n"), NULL, 10); //take next part of line, turn into llu and assign to idi
            guy.setOutgoingRelation(type, idi);
        }
    }

    fclose(fd);
    return people;
}

int main(int argc, char *argv[])
{
    FILE *fd;
    PersonsLL *persons;

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

    PersonsLL* people = parse(fd);

    for(int i = 0; i < people.getSize(); ++i)
        printf("%s\n", people.getPerson(i).getID);

    return 0;
}
