main: ./tests/tests
	./tests/tests

./bin/tree_iter.o: ./src/tree_iter.c
	gcc -Wall -Wextra -c ./src/tree_iter.c -o ./bin/tree_iter.o

./bin/unity.o: ./unity/unity.c ./unity/unity.h
	gcc -Wall -Wextra -c ./unity/unity.c -o ./bin/unity.o

./tests/tests: ./tests/tests.c ./bin/unity.o ./bin/tree_iter.o
	gcc -Wall -Wextra ./bin/unity.o ./bin/tree_iter.o ./tests/tests.c -o ./tests/tests

run:
	./tests/tests

clean:
	rm ./tests/tests
	rm ./bin/tree_iter.o
