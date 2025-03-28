all: dog

dog: main.o dog.o dog_database.o
	gcc main.o fun.o

main.o: main.cpp
	g++ -c main.cpp

dog.o: dog.cpp
	g++ -c dog.cpp
	
dog_database.o: dog_database.cpp
	g++ -c dog_database.cpp

clean:
	rm *.o