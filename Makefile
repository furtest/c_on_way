all : main.o map.o
	gcc -Wall $^ -o dev

functions.o : functions.c
	gcc -c functions.c

main.o : main.c functions.h
	gcc -c main.c

map.o: map.c
	gcc -c map.c

mem: all
	valgrind ./dev

run : all
	./dev

clean:
	rm -f peda* *.o dev main map
