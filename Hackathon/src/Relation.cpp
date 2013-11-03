#include "relation.h"
 /* The .cpp files are for source files and IMPLEMENTATION, i.e. not class defenitions! */

void RelationSet :: addIn(int newRelationType, unsigned long long id)
{
 in[relation_type].push_back(id);
}

void RelationSet :: addOut(int newRelationType, unsigned long long id)
{
 out[relation_type].push_back(id);
}
