#include "../include/parser.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <cstring>
#include <cstdlib>
#include <string>

Parser::Parser()
{
    //ctor
}

Parser::~Parser()
{
    //dtor
}

//parse the given file
std::list<Person>* Parser :: parse(std::ifstream& fileStream) {
    std::string buffer;
    std::list<Person>* people = new std::list<Person>;
    Person guy;// = (Person) malloc(sizeof(Person));
    int go = 0; //variable to determine whether we're between brackets

    while (std::getline(fileStream,buffer)) {

        //signify the start of adding relations
	if (buffer == "\n" || buffer == "" || buffer == " ")
			continue;

        if(buffer == "{"){
            go = 1;
            continue;
        }

        //signify the end of adding relations. Add person to LL
		else if(buffer == "}") {
            go = 0;
            people->push_front(guy); //add to LL
            guy = Person();
            continue;
        }


        //if not adding relations, then we are adding IDs
        if(!go) {
            long long unsigned idi = std::stoull(buffer.c_str());
			
            guy.setID(idi);
        }

        //if we are adding relations, split by space, send (type, id) to person class
        else {
            size_t spaceFoundPosition = buffer.find_last_of(" ");
            int type = 0;
            
            std::string firstWordInBuffer = buffer.substr(2,spaceFoundPosition-2);
            
            if(firstWordInBuffer == "FRIEND_OF") type = 0;
            else if(firstWordInBuffer == "MARRIED_TO") type = 1;
            else if(firstWordInBuffer == "HAS_DATED") type = 2;
            else if(firstWordInBuffer == "DISLIKES") type = 3;
            else if(firstWordInBuffer == "KNOWS") type = 4;
            
            guy.getRelationSet().addOut(type, std::stoull(buffer.substr(spaceFoundPosition,buffer.size()-1).c_str()));

        }
    }

    // fclose(fd); This method only uses the file pointer: it is not responsile
    // for closing the file handler.
    return people;
}
