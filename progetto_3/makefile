main: ./bin/tests
	./bin/tests

./bin/charArrayQueue.o: ./src/charArrayQueue.c
	gcc -Wall -Wextra -c ./src/charArrayQueue.c -o ./bin/charArrayQueue.o

./bin/unity.o: ./src/unity/unity.c ./src/unity/unity.h
	gcc -Wall -Wextra -c ./src/unity/unity.c -o ./bin/unity.o

./bin/tests: ./bin/charArrayQueue.o ./bin/unity.o
	gcc -Wall -Wextra ./bin/unity.o ./bin/charArrayQueue.o ./src/tests.c -o ./bin/tests

clean:
	rm ./bin/charArrayQueue.o
	rm ./bin/tests
