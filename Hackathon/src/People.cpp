#include "people.h"

People::People(){
	peopleMap = new Hashmap;
}

People::~People(){
	delete peopleMap;
}

//this function takes a pointer to a parser object and calls
bool People::load(std::list<Person>& l, bool analyse){
	//l is a pointer to a list of ALL of the people loaded by the parser

	//then we load each person in to the hashmap
	for(Person& p : l){
		peopleMap->emplace(p.get_id(),p);
	}

	if(analyse){
		compute_incoming_relations();
	}
	return true;
}

unsigned long long People :: get_total_people(){
	return peopleMap ? peopleMap->size() : 0;
}

void People::compute_incoming_relations(){
	//we iterate over every person in the hashmap
	//for each person, we get their outgoing relationships
	//we then add this outgoing relationship to the incoming relationships of the corresponding person

	for (Hashmap::iterator person = peopleMap->begin(); person != peopleMap->end(); ++person)
	{
		for (unsigned int i = 0; i < 5; ++i)
			for (unsigned long long buddyPersonID : person->second.get_relationSet().out[i])
			{
				Person* buddyPerson = &(peopleMap->find(buddyPersonID)->second);

				buddyPerson->get_relationSet().in[i].push_back(
					person->first);

				// This code takes the old buddy's IN relations and appends the person's OUT relations.
			}
	}
	

	/*

	for( Hashmap::iterator i = peopleMap->begin(), e = peopleMap->end() ; i != e ; ++i ) {
		//i->first
		//i->second
		RelationSet r = (i->second).get_relation();
		//iterating over the relations this person has and adding them to the
		for(int relationshiptype = 0; relationshiptype < 5; ++relationshiptype){
			std::list<unsigned long long>* relationships = r.get_out(relationshiptype);
			for(unsigned long long secondPerson : *relationships){
				//we are now iterating over the individual relationships. we are going to find the oerson in the peoplemap
				//and add an incoming relationship for the person value currently at i->first when the relationship type is 'relationshiptype'
				

				p->second.set_relation(
					(p->second.get_relation()).add_in(relationshiptype, i->first)
					);//adding the input value to the

				peoplemap[]
			}

		}
	}
	*/
}
