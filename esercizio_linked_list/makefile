all: ./bin/tests

./bin/list_iter.o: ./src/list_iter.c ./include/list_iter.h
	gcc -Wall -Wextra -c ./src/list_iter.c -o ./bin/list_iter.o

./bin/tests: ./bin/list_iter.o
	gcc -Wall -Wextra ./src/tests.c ./bin/list_iter.o -o ./bin/tests

run:
	./bin/tests

clean:
	rm ./bin/*
