#ifndef PEOPLE_H
#define PEOPLE_H

#include <list>
#include <unordered_map>
#include "person.h"

class People
{
    typedef std::unordered_map<unsigned long long, Person> Hashmap;
    private:
        Hashmap* peopleMap;
        void compute_incoming_relations();
    public:
        People();
        ~People();

        bool load(std::list<Person>& l, bool analyse);
        Person& get_person(unsigned long long person_id);
        unsigned long long get_total_people();
};

#endif // PEOPLE_H
