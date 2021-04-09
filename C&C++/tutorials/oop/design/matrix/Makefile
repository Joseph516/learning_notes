test: main.o matrix.o anticlock_matrix.o
	g++ -o test main.o matrix.o anticlock_matrix.o
     
main.o:
	g++ -c main.cpp
matrix.o:
	g++ -c matrix.cpp
anticlock_matrix.o:
	g++ -c anticlock_matrix.cpp

clean:
	rm test main.o matrix.o anticlock_matrix.o