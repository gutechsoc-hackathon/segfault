#include <string>
#include <sstream>
#include <iomanip>

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
		"knows           ",

		"is a friend of  ",
		"is married by   ",
		"was dated by    ",
		"is disliked by  ",
		"is known by     "};

	stringStream << "Person " << getID() << ":\n\toutgoing>";

	for (size_t i = 0; i < 5; ++i)
	{
		for (unsigned long long otherPerson : getRelationSet().out[i])
			stringStream << "\n\t  " << relationshipTypenames[i] 
			<< std::setw(19) << std::setfill('0') << otherPerson;
	}

	stringStream << "\n\tincoming>";

	for (size_t i = 0; i < 5; ++i)
	{
		for (unsigned long long otherPerson : getRelationSet().in[i])
			stringStream << "\n\t  " << relationshipTypenames[i + 5] 
			<< std::setw(19) << std::setfill('0') << otherPerson;
	}

	return stringStream.str();
}
