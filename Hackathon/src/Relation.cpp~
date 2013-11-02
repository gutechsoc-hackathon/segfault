#include <list>

class Relation {

public:
  
  static const int friend_of = 0;
  static const int married_to = 1;
  static const int has_dated = 2;
  static const int dislikes = 3;
  static const int knows = 4;
  
  std::list<unsigned long long> in[5];
  std::list<unsigned long long> out[5];
  
  std::list<unsigned long long> *get_in(int relation_type) { return &(in[relation_type]); }
  std::list<unsigned long long> *get_out(int relation_type) { return &(out[relation_type]); }

  void add_in(int relation_type, unsigned long long id) { in[relation_type].push_front(id); }
  void add_out(int relation_type, unsigned long long id) { out[relation_type].push_front(id); }

};
