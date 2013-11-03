#include "people.h"

People::People(){
	peopleMap = new Hashmap;
}

People::~People(){
	delete peopleMap;
}

//this function takes a pointer to a parser object and calls
bool People::load(std::list<Person>& personList, bool analyse){
	//l is a pointer to a list of ALL of the people loaded by the parser

	//then we load each person in to the hashmap
	for(Person& person : personList){
		peopleMap->emplace(person.getID(),person);
	}

	if(analyse){
		computeIncomingRelations();
	}
	return true;
}

unsigned long long People :: getTotalPeople(){
	return peopleMap ? peopleMap->size() : 0;
}

void People::computeIncomingRelations(){
	//we iterate over every person in the hashmap
	//for each person, we get their outgoing relationships
	//we then add this outgoing relationship to the incoming relationships of the corresponding person

	for (Hashmap::iterator person = peopleMap->begin(); person != peopleMap->end(); ++person)
	{
		for (unsigned int i = 0; i < 5; ++i)
		{
			for (unsigned long long buddyPersonID : person->second.getRelationSet().out[i])
			{
				Hashmap::iterator buddyPersonIterator = peopleMap->find(buddyPersonID);

				if (buddyPersonIterator == peopleMap->end())
					continue;

				buddyPersonIterator->second.getRelationSet().in[i].push_back(
					person->first);

				// This code takes the old buddy's IN relations and appends the person's OUT relations.
			}
		}
	}
}

People::Hashmap* People :: getPeopleMap()
{
	return peopleMap;
}
