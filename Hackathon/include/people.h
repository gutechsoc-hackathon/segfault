#ifndef PEOPLE_H
#define PEOPLE_H

#include <list>
#include <unordered_map>
#include "person.h"

class People
{
    public:
        typedef std::unordered_map<unsigned long long, Person> Hashmap;
    
    private:
        Hashmap* peopleMap;
        void computeIncomingRelations();
        unsigned long long totalpeople = 0;
    public:
        People();
        ~People();

        bool load(std::list<Person>& l, bool analyse);
        Person& getPerson(unsigned long long person_id);
        unsigned long long getTotalPeople();
        Hashmap* getPeopleMap();
};

#endif // PEOPLE_H
