#ifndef PERSON_H
#define PERSON_H

/* In C++ the interface goes in the header files and the implementation
    goes in the source (.cpp) files. */
    
#include "relation.h"
#include <string>

class Person {
public:
  unsigned long long id;
  RelationSet relation;

  unsigned long long getID();
  
  void setID(unsigned long long new_id);
  RelationSet& getRelationSet();
  void setRelationSet(RelationSet& relationSet);
  
  std::string getStringRepresentation() const;
};

#endif // PERSON_H
