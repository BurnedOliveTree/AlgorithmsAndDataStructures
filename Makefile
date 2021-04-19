CC = g++

main: main.o
	$(CC) main.o -o main
	rm *.o

main.o: main.cpp
	$(CC) main.cpp -c

clean:
	rm *.o main
