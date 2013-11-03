#include "../include/queries.h"
#include "../include/relation.h"
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

	return narcissistsFound;
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


	std::string currentUserInput = "";
	Person* currentPerson = &(*peopleMap->begin()).second;
	do {


		// Find noR.
		for (size_t i = 0; i < 5; ++i)
		{
			numberOfRelationships += currentPerson->getRelationSet().out[i].size();
		}


		std::cout << "+ ";
		std::cout << std::string(10,'-') << " +\n";

		std::string relationshipTypenames[] = {
			"is friends with",
			"is married to--",
			"has dated------",
			"dislikes-------",
			"knows----------",

			"is a friend of-",
			"is married by--",
			"was dated by---",
			"is disliked by-",
			"is known by----"};

		size_t currentRelationshipArrow = 0;

		for (size_t currentRow = 0; currentRow < 20;
			++currentRow)
		{
			std::cout << "| ";

			std::string personIDStr = std::to_string(currentPerson->getID()) + std::string(20 - std::to_string(currentPerson->getID()).length(),' ');

			if (currentRow == 5)
				std::cout << personIDStr.substr(0,5) << "     ";
			else if (currentRow == 6)
				std::cout << personIDStr.substr(5,5) << "     ";
			else if (currentRow == 7)
				std::cout << personIDStr.substr(10,5) << "     ";
			else if (currentRow == 8)
				std::cout << personIDStr.substr(15,5) << "     ";


			else if (currentRow == 4)
			{
				std::cout <<
					"Person:" << std::string(3,' ');
			}
			else
			{
				std::cout << std::string(10,' ');
			}
			std::cout << " |";

			// Draw any relationships.

			if (currentRelationshipArrow < 5)
			{
				if ((currentRow + 1) % 4 == 0)
				{
					std::cout << std::string(19,' ');
					// Draw the next row.
					for (size_t k = 0; k <
						currentPerson->getRelationSet().
						out[currentRelationshipArrow].size(); 
					++k)
						std::cout << "_____________ ";
				}

				else if ((currentRow - 1) % 4 == 0)
				{
					std::cout << std::string(19,' ');
					// Draw the next row.
					for (size_t k = 0; k <
						currentPerson->getRelationSet().
						out[currentRelationshipArrow-1].size(); 
					++k)
						std::cout << "````````````` ";
				}

				else if (currentRow % 4 == 0)
				{
					// Draw a relationship.

					std::cout << "-" << 
						relationshipTypenames[currentRelationshipArrow]
					<< "-> ";

					// Now, for each relationship of this type.

					std::string otherPeople = 
						currentPerson->getRelationSet()
						.out[currentRelationshipArrow].size() ? "" : "(nobody)";

					for (unsigned long long j :
					currentPerson->getRelationSet().
						out[currentRelationshipArrow])
					{
						otherPeople += "| P " + std::to_string(
							j).substr(0,4) + "... | ";
					}

					std::cout << otherPeople;

					++currentRelationshipArrow;
				}
			}

			std::cout << "\n";
		}

		std::cout << "+ ";
		std::cout << std::string(10,'-') << " +\n";

		std::cout << "Enter the first four digits of the person ID of the person you would like to display, or the"
			" full person ID of a person you would like to display (or nothing to exit)>";
		std::cin >> currentUserInput;

		// Iterate thru all of the outgoing r/ships of THIS person, and find
		// the one the user wants.

		bool fullName = currentUserInput.length() != 4;

		bool foundUserChoice = false;

		if (fullName)
		{
			auto searchPerson = peopleMap->find(std::stoull(currentUserInput.c_str()));

			if (searchPerson != peopleMap->end())
			{
				// We found a person.
				currentPerson = &searchPerson->second;
				foundUserChoice = true;
			}
		}
		else
		{
			for (size_t k = 0; k < 5; ++k)
			{
				for (unsigned long long j :
				currentPerson->getRelationSet().
					out[k])
				{
					// For every r.ship.


					if (std::to_string(j).substr(0,4) == currentUserInput)
					{
						auto searchPerson = peopleMap->find(j);

						if (searchPerson != peopleMap->end())
						{
							// We found a person.
							currentPerson = &searchPerson->second;
							foundUserChoice = true;
						}
					}
				}
			}
		}

		if (foundUserChoice == false)
		{
			std::cout << "NO SUCH PERSON. PRESS ANY KEY...\n";
			std::getchar();
		}

		for (size_t k = 0; k < 500; ++k);
		std::cout<<"\n";

	} while(currentUserInput != "");
}
