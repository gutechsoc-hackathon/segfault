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

#include "people.h"
#include "person.h"
#include "relation.h"
#include "parser.h"

int main(int argc, char * argv[])
{
	if (argc < 2)
		return 1;

	std::cout << "Attempting to load file from disk...\n";
	std::ifstream readFileStream("C:\\relationships-small.txt");

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

	std::cout << "Done, creating a QueryCaller to run queries with...\n";

	QueryCaller queryCaller(people);
	std::cout << "There are " << queryCaller.howManyNarcissists() << "\n narcissists.\n";

	std::cout << "All done! :)\n";
	std::getchar();
	return 0;
}
