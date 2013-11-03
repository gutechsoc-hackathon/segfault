CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=$(wildcard Hackathon/src/*.cpp)

sas: $(SOURCES:Hackathon/src/%.cpp=Hackathon/obj/%.o)
	$(CC) $^ -o $@

Hackathon/obj/%.o: Hackathon/src/%.cpp
	$(CC) $(CFLAGS) $< -o $@