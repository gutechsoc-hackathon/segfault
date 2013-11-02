#include "People.h"

People::People(){
    peoplemap = new hashmap;
}

People::~People(){
    delete peoplemap;
}

//this function takes a pointer to a parser object and calls
bool People::Load(std::list<Person>& l, bool analyse){
    //l is a pointer to a list of ALL of the people loaded by the parser

    //then we load each person in to the hashmap
    for(Person& p : l){
        peoplemap.push_back(p.get_id(), p
        totalpeople++;
    }

    if(analyse){
        compute_incoming_relations();
    }
}

unsigned long long get_total_people(){
    return totalpeople;
}

Person

People::compute_incoming_relations(){
    //we iterate over every person in the hashmap
    //for each person, we get their outgoing relationships
    //we then add this outgoing relationship to the incoming relationships of the corresponding person
    for( hashmap::const_iterator i = numbers.begin(), e = numbers.end() ; i != e ; ++i ) {
        //i->first
        //i->second
        Relation r = (i->second).get_relations();
        //iterating over the relations this person has and adding them to the
        for(int relationshiptype = 0; i<5; i++){
            std::list<unsigned long long> relationships = *r.get_out(relationshiptype);
            for(int k = 0; k<relationships.size(); k++){
                //we are now iterating over the individual relationships. we are going to find the oerson in the peoplemap
                //and add an incoming relationship for the person value currently at i->first when the relationship type is 'relationshiptype'
                Person p = peoplemap[relationships.get(k)];
                p.set_relations((p.get_relations()).add_in(relationshiptype, i->first));//adding the input value to the
                peoplemap[]
            }

        }
    }
}
