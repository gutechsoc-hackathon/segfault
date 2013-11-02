#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
    public:
        People(fileloader* f);
        bool load();
        Person get_person(unsigned long person_id);
        int get_total_people();
        virtual ~People();
    protected:
    private:
        unsigned int totalPeople;
        void add_people_to_map();
        void compute_incoming_relations();


};

#endif // PEOPLE_H
