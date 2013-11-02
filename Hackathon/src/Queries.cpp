#include "queries.h"

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
	return (size_t) people.get_total_people();
}
