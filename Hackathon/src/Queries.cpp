#include "queries.h"
#include "relation.h"
#include <list>
#include <iostream>
#include <iomanip>
#include <string>

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
	return (size_t)people.getTotalPeople();
}

size_t QueryCaller::howManyNarcissists()
{
	auto peopleMap = people.getPeopleMap();
	unsigned long long narcissistsFound = 0;
	bool relationshipFound;
	unsigned int i;

	for (People::Hashmap::iterator person = peopleMap->begin(); person != peopleMap->end(); ++person)
	{
		relationshipFound = false;
		i = 0;

		while (i < 5 && relationshipFound == false)
		{
			for (unsigned long long buddyPersonID : person->second.getRelationSet().out[i])
			{
				People::Hashmap::iterator buddyPersonIterator = peopleMap->find(buddyPersonID);

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

Person& QueryCaller::mostDisliked()
{
	Person* personPointer = NULL;
	int mostdislikes = 0;
	for (std::pair<unsigned long long, Person> hashmapRow : *people.getPeopleMap())
	{
		Person& p = hashmapRow.second;
		int dislikes = p.getRelationSet().in[RelationSet::dislikes].size();

		if (dislikes > mostdislikes){
			mostdislikes = dislikes;
			personPointer = &p;
		}
	}

	return *personPointer;
}

size_t QueryCaller::numberOfMutualFriends()
{
	int friendships = 0;
	for (std::pair<unsigned long long, Person> hashmapRow : *people.getPeopleMap())
	{
		Person& p = hashmapRow.second;
		std::list<unsigned long long> going = p.getRelationSet().out[RelationSet::friend_of];
		std::list<unsigned long long> coming = p.getRelationSet().in[RelationSet::friend_of];

		for (auto i : going)
		for (auto j : coming)
		if (i == j)
			friendships++;
	}

	return (friendships / 2);
}

std::pair<long, long> QueryCaller::averageNumberOfRelationshipsForOddEvenPeople()
{
	int oddPeople = 0;
	int evenPeople = 0;
	int oddRels = 0;
	int evenRels = 0;

	for (std::pair<unsigned long long, Person> hashmapRow : *people.getPeopleMap())
	{
		Person& p = hashmapRow.second;
		if ((p.getID() % 10) % 2 == 0)
		{
			evenPeople++;
			evenRels += p.getRelationSet().in[RelationSet::friend_of].size() +
				p.getRelationSet().in[RelationSet::dislikes].size() +
				p.getRelationSet().in[RelationSet::has_dated].size() +
				p.getRelationSet().in[RelationSet::knows].size() +
				p.getRelationSet().in[RelationSet::married_to].size() +
				p.getRelationSet().out[RelationSet::friend_of].size() +
				p.getRelationSet().out[RelationSet::dislikes].size() +
				p.getRelationSet().out[RelationSet::has_dated].size() +
				p.getRelationSet().out[RelationSet::knows].size() +
				p.getRelationSet().out[RelationSet::married_to].size();
		}

		else
		{
			oddPeople++;
			oddRels += p.getRelationSet().in[RelationSet::friend_of].size() +
				p.getRelationSet().in[RelationSet::dislikes].size() +
				p.getRelationSet().in[RelationSet::has_dated].size() +
				p.getRelationSet().in[RelationSet::knows].size() +
				p.getRelationSet().in[RelationSet::married_to].size() +
				p.getRelationSet().out[RelationSet::friend_of].size() +
				p.getRelationSet().out[RelationSet::dislikes].size() +
				p.getRelationSet().out[RelationSet::has_dated].size() +
				p.getRelationSet().out[RelationSet::knows].size() +
				p.getRelationSet().out[RelationSet::married_to].size();
		}
	}
		std::pair<long, long> result;
		result.first = evenRels / evenPeople;
		result.second = oddRels / oddPeople;

		return result;
}

void QueryCaller :: drawVisualisation()
{
	system("CLS");

	size_t numberOfRelationships = 0;

	auto peopleMap = people.getPeopleMap();
	auto currentPerson = peopleMap->begin();

	// Find noR.
	for (size_t i = 0; i < 5; ++i)
	{
		numberOfRelationships += currentPerson->second.getRelationSet().out[i].size();
	}


	std::cout << "+ ";
	std::cout << std::string(19,'-') << " +\n";

	std::string relationshipTypenames[] = {
		"is friends with-",
		"is married to---",
		"has dated-------",
		"dislikes--------",
		"knows-----------",

		"is a friend of--",
		"is married by---",
		"was dated by----",
		"is disliked by--",
		"is known by-----"};

	size_t currentRelationshipArrow = 0;

	for (size_t currentRow = 0; currentRow < 13;
		++currentRow)
	{
		std::cout << "| ";

		if (currentRow == 5)
		{
			std::cout << std::setw(19) << std::setfill('0') 
		<< currentPerson->first;
			
		}
		else if (currentRow == 4)
		{
			std::cout <<
				"Person:" << std::string(12,' ');
		}
		else
		{
			std::cout << std::string(19,' ');
		}
		std::cout << " |";

		// Draw any relationships.

		
		if (currentRow % 3 == 0 && currentRelationshipArrow < 5)
		{
			// Draw a relationship.

			std::cout << "----" << 
				relationshipTypenames[currentRelationshipArrow]
				<< "--->";

			++currentRelationshipArrow;
		}

		std::cout << "\n";
	}

	std::cout << "+ ";
	std::cout << std::string(19,'-') << " +\n";

}
