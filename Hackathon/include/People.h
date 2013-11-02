#ifndef PEOPLE_H
#define PEOPLE_H

#include <list>
#include "include\Person.h"

class People
{
    typedef std::unordered_map<unsigned long long, Person> Hashmap;
    private:
        Hashmap peopleMap;
        void compute_incoming_relations();
    public:
        People();
        ~People();

        //The load function takes a list of person objects and loads them in the the massivce hashmap.
        //if analyse is set to true, it goes through and analyses all of the data.
        //analyse should only be set to true if this is the first time we are loading objects in to the hashmap.
        bool load(std::list<Person>& l, bool analyse);
        Person& get_person(unsigned long long person_id);
        unsigned long long get_total_people();
};

#endif // PEOPLE_H
