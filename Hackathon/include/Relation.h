#ifndef RELATION_H
#define RELATION_H

#include <list>

class RelationSet {
public:
  static const int friend_of = 0,
    married_to = 1,
    has_dated = 2,
    dislikes = 3,
    knows = 4;
  
  std::list<unsigned long long> in[5];
  std::list<unsigned long long> out[5];
  
  std::list<unsigned long long> *get_in(int relation_type);
  std::list<unsigned long long> *get_out(int relation_type);

  void add_in(int relation_type, unsigned long long id);
  void add_out(int relation_type, unsigned long long id);
};


#endif // RELATION_H
