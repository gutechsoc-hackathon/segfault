#ifndef PERSON_H
#define PERSON_H

/* In C++ the interface goes in the header files and the implementation
    goes in the source (.cpp) files. */
    

#include "relation.h"

class Person {
public:
  unsigned long long id;
  RelationSet relation;

  unsigned long long get_id();
  
  void set_id(unsigned long long new_id);
  RelationSet& get_relationSet();
  void set_relationSet(RelationSet& relationSet);
};


#endif // PERSON_H
