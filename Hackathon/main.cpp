#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list>
#include "include/People.h"
#include "include/Person.h"
#include "include/Relation.h"


//parse the given file
static std::list<Person> *parse(FILE *fd) {
    char bf[1024];
    std::list<Person> people;
    Person *guy = new Person;// = (Person) malloc(sizeof(Person));
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
            people.push_front(guy); //add to LL
            delete guy;
            Person *guy = new Person;
            continue;
        }


        //if not adding relations, then we are adding IDs
        if(!go) {
            long long unsigned idi = strtoull(bf, NULL, 10);
            guy.set_id(idi);
        }

        //if we are adding relations, split by space, send (type, id) to person class
        else {
            char *part;
            part = strtok(bf, " ");
            int type;
            if(part == "FRIEND_OF") type = 0;
            else if(part == "MARRIED_TO") type = 1;
            else if(part == "HAS_DATED") type = 2;
            else if(part == "DISLIKES") type = 3;
            else if(part == "KNOWS") type = 4;
            long long unsigned idi = strtoull(strtok(NULL, "\n"), NULL, 10); //take next part of line, turn into llu and assign to idi
            Relation rel = (Relation)malloc(sizeof(Relation));
            rel.add_out(type, idi);
            guy.set_relation(rel);
        }
    }

    fclose(fd);
    return people;
}

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
