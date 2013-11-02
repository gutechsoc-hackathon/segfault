#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
    typedef std::tr1::unordered_map< unsigned long long, Person > hashmap;
    public:
        People(fileloader* f);
        bool load();
        Person get_person(unsigned long long person_id);
        int get_total_people();
        virtual ~People();
    protected:
    private:
        hashmap peoplemap;
        unsigned int totalPeople;

        void add_people_to_map();
        void get_person_at_index();
        void compute_incoming_relations();


};

#endif // PEOPLE_H
