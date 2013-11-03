#CC=g++
#CFLAGS=-c -Wall
#OBJECTS=main.o Parser.o People.o Person.o Queries.o Relation.o
#SOURCES=main.cpp Parser.cpp People.cpp Person.cpp Queries.cpp Relation.cpp
#SOURCES=$(wildcard Hackathon/src/*.cpp)

#sas: $(SOURCES:%.cpp=Hackathon/obj/%.o)
#	$(CC) $< -o $@

#Hackathon/obj/%.o: Hackathon/src/%.cpp
#	$(CC) $(CFLAGS) $< -o $@

CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=$(wildcard Hackathon/src/*.cpp)

sas: $(SOURCES:Hackathon/src/%.cpp=Hackathon/obj/%.o)
	$(CC) $^ -o $@

Hackathon/obj/%.o: Hackathon/src/%.cpp
	$(CC) $(CFLAGS) $< -o $@