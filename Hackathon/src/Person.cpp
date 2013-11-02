#include "person.h"
#include "relation.h"

/* Methods are defined here. The class defenition goes in the HEADER FILE */

  unsigned long long Person :: get_id() 
  {
    return id; 
  }
  
  RelationSet& Person :: get_relationSet()
  {
    return relation;
  }
  
  void Person :: set_id(unsigned long long new_id)
  {
    id = new_id; 
  }
  void Person :: set_relationSet(RelationSet& new_relation)
  {
    relation = new_relation;
  }
