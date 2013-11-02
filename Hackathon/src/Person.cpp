#include "Person.h"

/* Methods are defined here. The class defenition goes in the HEADER FILE */

  unsigned long long Person :: get_id() 
  {
    return id; 
  }
  
  Relation Person :: get_relation()
  {
    return relation;
  }
  
  void Person :: set_id(unsigned long long new_id)
  {
    id = new_id; 
  }
  void Person :: set_relation(Relation new_relation)
  {
    relation = new_relation;
  }
