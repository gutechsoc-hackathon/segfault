#include "queries.h"

QueryCaller::QueryCaller(People& newPeople) :
	people(newPeople)
{
    //ctor
}

QueryCaller::~QueryCaller()
{
    //dtor
}

size_t QueryCaller::howManyPeopleAreThere()
{
	return (size_t) people.getTotalPeople();
}

size_t QueryCaller::howManyNarcissists()
{
	auto peopleMap = people.peopleMap;
	unsigned long long narcissistsFound = 0;
	bool relationshipFound;
	unsigned int i;
	
	for (Hashmap::iterator person = peopleMap->begin(); person != peopleMap->end(); ++person)
        {
        	relationshipFound = false;
        	i = 0;
        	
        	while (i < 5 && relationshipFound == false)
        	{
        		for (unsigned long long buddyPersonID : person->second.getRelationSet().out[i])
        		{
        			Hashmap::iterator buddyPersonIterator = peopleMap->find(buddyPersonID);
        			
        			if (buddyPersonID == person->first)
        			{
        				relationshipFound = true;
        				narcissistsFound++;
        				break;
        			}
        		}
				
        		i++;
        	}
        } 	
	
	return 0;
}
