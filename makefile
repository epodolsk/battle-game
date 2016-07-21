CPP = g++
CPPFLAGS  = -g -Wall

default: a4

a4:  main.o utilities.o Creature.o BabaYaga.o Barbarian.o Bluemen.o Medusa.o Potter.o Queue.o Stack.o
	$(CPP) $(CPPFLAGS) -o a4 main.o utilities.o Creature.o BabaYaga.o Barbarian.o Bluemen.o Medusa.o Potter.o Queue.o Stack.o

main.o:  main.cpp Creature.hpp utilities.hpp Queue.hpp BabaYaga.hpp Barbarian.hpp Bluemen.hpp Medusa.hpp Potter.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

utilities.o:  utilities.cpp utilities.hpp
	$(CPP) $(CPPFLAGS) -c utilities.cpp
	
Queue.o: Queue.cpp Queue.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Queue.cpp
	
Stack.o: Stack.cpp Stack.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Stack.cpp
	
Creature.o:  Creature.cpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Creature.cpp
	
BabaYaga.o:  BabaYaga.cpp BabaYaga.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c BabaYaga.cpp

Barbarian.o:  Barbarian.cpp Barbarian.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Barbarian.cpp

Bluemen.o:  Bluemen.cpp Bluemen.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Bluemen.cpp

Medusa.o:  Medusa.cpp Medusa.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Medusa.cpp
	
Potter.o:  Potter.cpp Potter.hpp Creature.hpp
	$(CPP) $(CPPFLAGS) -c Potter.cpp

clean: 
	$(RM) a4 *.o *~