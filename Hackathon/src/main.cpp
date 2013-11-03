/*

Main.cpp

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <list>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

#include "people.h"
#include "person.h"
#include "relation.h"
#include "parser.h"

int main(int argc, char * argv[])
{
	clock_t startTime;
  	startTime = std::clock();
  	//diff = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
	if (argc < 2)
		return 1;

	std::cout << "Attempting to load file from disk...\n";
	std::ifstream readFileStream("/home/ubuntu/relationships-big.txt");

	if (readFileStream.bad())
		return 2;

	Parser parser;
	std::list<Person>* pointerToPeopleList = parser.parse(readFileStream);

	std::cout << "Done, loading list of people in to hashmap...\n";
	People people;
	people.load(*pointerToPeopleList, true);
	delete pointerToPeopleList;

	std::cout << "Done, printing out the hashmap...\n";

	for (std::pair<unsigned long long, Person> hashmapRow : *people.getPeopleMap())
	{
		std::cout << hashmapRow.second.getStringRepresentation() << "\n";	
	}

	std::cout << "Done, creating a QueryCaller to run queries with...\n\n";

	QueryCaller queryCaller(people);
	
	//starting to query
	std::cout << "Question A: Finding how many people there are.\n";
	std::cout << "There are " << queryCaller.howManyPeopleAreThere() << " people.\n";
	std::cout << "Took " << (std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question B: Finding The average number of relationships (incoming and outgoing) for people with off and even numbers.\n";
	std::pair<long, long> evenodd = queryCaller.averageNumberOfRelationshipsForOddEvenPeople();
	std::cout << "The averages are: " << evenodd.first << " for even. " << evenodd.second << " for odd.\n";
	std::cout << "Took " << (std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question C: Finding how many narcissists there are.\n";
	std::cout << "There are " << queryCaller.howManyNarcissists() << " narcissists.\n";
	std::cout << "Took " << (std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question D: Finding The number of mutual friends.\n";
	std::cout << "There are " << queryCaller.numberOfMutualFriends() << " two-way relationships.\n";
	std::cout << "Took " << (std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question E: Finding The most disliked person.\n";
	std::cout << "Poor person ID " << queryCaller.MostDisliked().getID() << " is the most disliked.\n";
	std::cout << "Took " << (std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "All done! :)\n";
	std::getchar();
	return 0;
}
