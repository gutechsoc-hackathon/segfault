#include "Relation.h"
 /* The .cpp files are for source files and IMPLEMENTATION, i.e. not class defenitions! */

std::list<unsigned long long>& get_in(int relation_type)
{
 return in[relation_type];
}
std::list<unsigned long long>& get_out(int relation_type)
{
 return out[relation_type];
}

void RelationSet :: add_in(int relation_type, unsigned long long id)
{
 in[relation_type].push_back(id);
}

void RelationSet :: add_out(int relation_type, unsigned long long id)
{
 out[relation_type].push_back(id);
}
