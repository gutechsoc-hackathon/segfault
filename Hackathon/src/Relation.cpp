#include "Relation.h"
 /* The .cpp files are for source files and IMPLEMENTATION, i.e. not class defenitions! */

void RelationSet :: add_in(int relation_type, unsigned long long id)
{
 in[relation_type].push_back(id);
}

void RelationSet :: add_out(int relation_type, unsigned long long id)
{
 out[relation_type].push_back(id);
}
