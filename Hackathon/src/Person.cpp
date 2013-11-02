
class Person {
  
public:
  

  unsigned long long id;
  Relation relation;


  unsigned long long get_id() { return id; }
  Relation get_relation() { return relation; }
  
  void set_id(unsigned long long new_id) { id = new_id; }
  void set_relation(Relation new_relation) { relation = new_relation; }

};
