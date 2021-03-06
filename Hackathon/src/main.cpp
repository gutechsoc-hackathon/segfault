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

#include "../include/people.h"
#include "../include/person.h"
#include "../include/relation.h"
#include "../include/parser.h"
#include "../include/queries.h"

int main(int argc, char * argv[])
{
	clock_t startTime;
  	startTime = std::clock();
  	//diff = ( std::clock() - start ) / (double)CLOCKS_PER_SEC;
	//if (argc < 2)
	//	return 1;

	std::cout << "Attempting to load file from disk...\n";
	//std::ifstream readFileStream("/home/ubuntu/program/segfault/relationships-small.txt");
	std::ifstream readFileStream("/home/ubuntu/relationships-big.txt");

	if (!readFileStream.is_open()) {
	  std::cout << "not open, tough";
		return 2;
	}
	if (readFileStream.bad())
		return 2;
	
	std::cout << "Successfully loaded file.\n\n";
	
	//parsing the file in to a list of Person objects
	std::cout << "Parsing File in to People objects...\n";
	startTime = std::clock();
	
	Parser parser;
	std::list<Person>* pointerToPeopleList = parser.parse(readFileStream);
	
	std::cout << "Finished parsing. Done in" << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms.\n\n";
	
	//Loading the Person objects in to the People data structure
	std::cout << "Loading list of people in to data structure and analysing them...\n";
	startTime = std::clock();
	
	People people;
	people.load(*pointerToPeopleList, true);
	delete pointerToPeopleList;
	
	std::cout << "Finished loading/analysing. Done in " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms.\n\n";
	

	/*for (std::pair<unsigned long long, Person> hashmapRow : *people.getPeopleMap())
	{
		std::cout << hashmapRow.second.getStringRepresentation() << "\n";	
	}*/

	std::cout << "Loading stage complete.\nCreating a query caller object and starting queries...\n\n";

	QueryCaller queryCaller(people);

	//resetting the clock before querying
	startTime = std::clock();
	
	//starting to query
	std::cout << "Question A: Finding how many people there are.\n";
	std::cout << "There are " << queryCaller.howManyPeopleAreThere() << " people.\n";
	std::cout << "Took " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question B: Finding The average number of relationships (incoming and outgoing) for people with off and even numbers.\n";
	std::pair<long, long> evenodd = queryCaller.averageNumberOfRelationshipsForOddEvenPeople();
	std::cout << "The averages are: " << evenodd.first << " for even. " << evenodd.second << " for odd.\n";
	std::cout << "Took " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question C: Finding how many narcissists there are.\n";
	std::cout << "There are " << queryCaller.howManyNarcissists() << " narcissists.\n";
	std::cout << "Took " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question D: Finding The number of mutual friends.\n";
	std::cout << "There are " << queryCaller.numberOfMutualFriends() << " two-way relationships.\n";
	std::cout << "Took " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "Question E: Finding The most disliked person.\n";
	std::cout << "Poor person ID " << queryCaller.mostDisliked().getID() << " is the most disliked.\n";
	std::cout << "Took " << ((std::clock() - startTime ) / (double)CLOCKS_PER_SEC)*1000 << "ms to execute\n\n";
	startTime = std::clock();
	
	std::cout << "All done! :)\n\n";
	
	std::cout << "Would you like to run a visualisation? (y/n): ";
	char answer = std::getchar();
	std::cout << "\n";
	if(answer == 'y'){
		queryCaller.drawVisualisation();
	}
	
	std::getchar();
	return 0;
}
