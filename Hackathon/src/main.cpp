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
#include "people.h"
#include "person.h"
#include "relation.h"
#include "parser.h"

int main(int argc, char * argv[])
{
	// 1. Load the file into a file pointer.
	//check if there is a specified input file
	//if (argc < 2)
	//

	//return -99;

	std::ifstream fd("C:\\relationships-small.txt");
	if (fd.bad())
		return -88;

	std::cout << "Found file... Loading the data from the file..." <<std::endl;
	// 2. Use the parser class to create a list of people.
	Parser parser;
	std::list<Person>* pointerToPeopleList = parser.parse(fd);

	std::cout << "Done." << std::endl << std::endl;

	// 3. Creating a People object and passing it a pointer to the people liat.
	std::cout << "loading list of people in to hashmap..." << std::endl;
	People p;
	p.load(*pointerToPeopleList, true);
	std::cout << "Done." << std:: endl << std::endl;

	for (std::pair<unsigned long long, Person> hashmapRow : *p.getPeopleMap())
	{
		std::cout << hashmapRow.second.getStringRepresentation() << "\n";	
	}

	delete pointerToPeopleList;

	std::getchar();
	return 0;
}
