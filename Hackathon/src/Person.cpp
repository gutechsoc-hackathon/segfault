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
std::string Person :: getStringRepresentation()
{
	std::stringstream  stringStream;
	std::string relationshipTypenames[] = {
		"is friends with ",
		"is married to   ",
		"has dated       ",
		"dislikes        ",
		"knows           "};

	stringStream << "Person " << getID() << ":";

	for (size_t i = 0; i < 5; ++i)
		for (unsigned long long otherPerson : getRelationSet().out[i])
			stringStream << "\n\t" << relationshipTypenames[i] 
			<< std::setw(19) << std::setfill('0') << otherPerson;

	return stringStream.str();
}
