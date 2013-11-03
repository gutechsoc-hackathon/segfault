#ifndef PARSER_H
#define PARSER_H

#include "person.h"

class Parser
{
 public:
   Parser();
   ~Parser();
   
    std::list<Person>* parse(std::ifstream& fd);
};

#endif // PARSER_H
