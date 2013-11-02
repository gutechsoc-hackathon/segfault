/*

Main.cpp

*/

#include <list>

int main(int argc, char * argc[])
{
  // 1. Load the file into a file pointer.
  
  FILE* filePointer = ...
  
  // 2. Use the parser class to create a list of people.
  
  std::list& referenceToPeopleList = Parser::...
  
  // 3. Query the database.
}
