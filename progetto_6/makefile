main: ./tests/tests
	./tests/tests

./bin/ram.o: ./src/ram.c
	gcc -Wall -Wextra -c ./src/ram.c -o ./bin/ram.o

./bin/unity.o: ./unity/unity.c ./unity/unity.h
	gcc -Wall -Wextra -c ./unity/unity.c -o ./bin/unity.o

./tests/tests: ./tests/tests.c ./bin/unity.o ./bin/ram.o
	gcc -Wall -Wextra ./bin/unity.o ./bin/ram.o ./tests/tests.c -o ./tests/tests

run:
	./tests/tests

clean:
	rm ./tests/tests
	rm ./bin/ram.o

