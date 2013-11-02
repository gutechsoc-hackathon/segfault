#include "Parser.h"

Parser::Parser()
{
    //ctor
}

Parser::~Parser()
{
    //dtor
}


//parse the given file
std::list<Person> Person :: parse(FILE *fd) {
    std::string buffer;
    std::list<Person> people;
    Person guy;// = (Person) malloc(sizeof(Person));
    int go = 0; //variable to determine whether we're between brackets

    while (getline(buffer)) {

        //signify the start of adding relations
        if(buffer == '{'){
            go = 1;
            continue;
        }

        //signify the end of adding relations. Add person to LL
        else if(buffer == '}') {
            go = 0;
            people.push_front(guy); //add to LL
            guy = Person();
            continue;
        }


        //if not adding relations, then we are adding IDs
        if(!go) {
            long long unsigned idi = strtoull(buffer.c_str());
            guy.set_id(idi);
        }

        //if we are adding relations, split by space, send (type, id) to person class
        else {
            size_t spaceFoundPosition = buffer.find_first_of(" ");
            int type;
            
            std::string firstWordInBuffer = buffer.substr(0,spaceFoundPosition);
            
            if(firstWordInBuffer == "FRIEND_OF") type = 0;
            else if(firstWordInBuffer == "MARRIED_TO") type = 1;
            else if(firstWordInBuffer == "HAS_DATED") type = 2;
            else if(firstWordInBuffer == "DISLIKES") type = 3;
            else if(firstWordInBuffer == "KNOWS") type = 4;
            
            Relation rel;
            rel.add_out(type, strtoull(buffer.substr(buffer.begin() + spaceFoundPosition,buffer.end()).c_str());
            guy.set_relation(rel);
        }
    }

    // fclose(fd); This method only uses the file pointer: it is not responsile
    // for closing the file handler.
    return people;
}
