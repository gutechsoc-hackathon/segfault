#ifndef PERSON_H
#define PERSON_H


/* In C++ the interface goes in the header files and the implementation
    goes in the source (.cpp) files. */
    
class Person
{
    public:
        Person();
        Relation get_relations();
        virtual ~Person();
    protected:
    private:
};

#endif // PERSON_H
