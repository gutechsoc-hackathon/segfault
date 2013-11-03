#include "person.h"
#include "relation.h"

/* Methods are defined here. The class defenition goes in the HEADER FILE */

unsigned long long Person :: getID() 
{
	return id; 
}

RelationSet& Person :: getRelationSet()
{
	return relation;
}

void Person :: setID(unsigned long long newID)
{
	id = newID; 
}
void Person :: setRelationSet(RelationSet& newRelation)
{
	relation = newRelation;
}
