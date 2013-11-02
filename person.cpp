
class Person {

private:
  
  unsigned long long id;
  Relation relation;

public:
  
  unsigned long long get_id() { return id; }
  Relation get_relation() { return relation; }
  
  void set_id(unsigned long long id) { this.id = id; }
  void set_relation(Relation relation) { this.relation = relation; }

}
