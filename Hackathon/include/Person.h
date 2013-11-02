#ifndef PERSON_H
#define PERSON_H

/* In C++ the interface goes in the header files and the implementation
    goes in the source (.cpp) files. */
    
class Person {
public:
  unsigned long long id;
  Relation relation;

  unsigned long long get_id();
  Relation get_relation();
  
  void set_id(unsigned long long new_id);
  void set_relation(Relation new_relation);
};


#endif // PERSON_H
