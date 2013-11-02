#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
    typedef std::unordered_map<unsigned long long, Person> hashmap;
    //typedef std::tr1::unordered_map< unsigned long long, Person > hashmap;
    public:
        People();
        bool load(std::list<Person> l, bool analyse);
        Person get_person(unsigned long long person_id);
        unsigned long long get_total_people();
        virtual ~People();
    protected:
    private:
        hashmap peoplemap;
        unsigned long long totalPeople = 0;

        void compute_incoming_relations();


};

#endif // PEOPLE_H
