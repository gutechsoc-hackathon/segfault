#ifndef PARSER_H
#define PARSER_H


class Parser
{
   public:
   Parser();
   ~Parser();
   
    std::list<Person> parse(FILE * fd);
};


Parser::Parser()
{
    //ctor
}

Parser::~Parser()
{
    //dtor
}

#endif // PARSER_H
