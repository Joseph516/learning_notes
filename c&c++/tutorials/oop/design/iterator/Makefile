test: main.o array_collection.o array_iterator.o
	g++ -std=c++11 -o test main.o array_collection.o array_iterator.o
     
main.o:
	g++ -std=c++11 -c main.cpp
array_collection.o:
	g++ -std=c++11 -c array_collection.cpp
array_iterator.o:
	g++ -std=c++11 -c array_iterator.cpp

clean:
	rm test main.o array_collection.o array_iterator.o