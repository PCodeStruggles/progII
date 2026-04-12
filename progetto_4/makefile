main: ./bin/tests
	./bin/tests

./bin/unity.o: ./src/unity/unity.c ./src/unity/unity.h
	gcc -Wall -Wextra -c ./src/unity/unity.c -o ./bin/unity.o

./bin/linkedListQueue.o: ./src/linkedListQueue.c ./include/linkedListQueue.h ./include/charQueueADT.h
	gcc -Wall -Wextra -c ./src/linkedListQueue.c -o ./bin/linkedListQueue.o

./bin/tests: ./bin/linkedListQueue.o ./bin/unity.o ./src/tests.c
	gcc -Wall -Wextra  ./src/tests.c ./bin/unity.o ./bin/linkedListQueue.o -o ./bin/tests

clean:
	rm ./bin/linkedListQueue.o
