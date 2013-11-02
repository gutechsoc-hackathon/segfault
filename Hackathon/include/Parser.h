#ifndef PARSER_H
#define PARSER_H


class Parser
{
   public:
   Parser();
   ~Parser();
   
    std::list<Person> parse(FILE * fd);
};

#endif // PARSER_H
