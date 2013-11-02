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
	if (argc < 2)
		return -99;

	std::ifstream fd = std::ifstream("C:\\Users\\Michael McKay\\Desktop\\segfault-master\\relationships-small.txt");
	if (fd.bad())
		return -88;

	// 2. Use the parser class to create a list of people.
	Parser parser;
	std::list<Person>* pointerToPeopleList = parser.parse(fd);

	// 3. Query the database.

	for (auto x : *pointerToPeopleList)
	{
		std::cout << x.get_relationSet().out[0].back() << std::endl;
	}

	delete pointerToPeopleList;

	std::getchar();
	return 0;
}
