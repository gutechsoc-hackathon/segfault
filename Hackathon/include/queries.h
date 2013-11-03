#ifndef QUERIES_H
#define QUERIES_H

#include "people.h"

// When you're writing a query, mark your name beside the one you are writing so we don't have duplicates, thanks.

class QueryCaller
{
	// This class is constructed with a People object, and will continue to use
	// that people object for querying throughout it's existence.
	private:
		People& people;
    public:
        QueryCaller(People& people);
        ~QueryCaller();

		size_t howManyPeopleAreThere(); // Done!
		std::pair<long,long> averageNumberOfRelationshipsForOddEvenPeople();

		size_t howManyNarcissists();
		size_t numberOfMutualFriends();
		Person& mostDisliked();

		void drawVisualisation(); 
		// I think it would be cool to print an ASCII art map to
		// the terminal for this one.

		Person& whichPersonHasTheLongestCycleOfFriendOfRelationships();
};

#endif // QUERIES_H
