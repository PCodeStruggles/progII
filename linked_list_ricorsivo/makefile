main: ./bin/tests
	./bin/tests

./bin/list_rec.o: ./src/list_rec.c
	gcc -Wall -Wextra -c ./src/list_rec.c -o ./bin/list_rec.o

./bin/unity.o: ./unity/unity.c ./unity/unity.h
	gcc -Wall -Wextra -c ./unity/unity.c -o ./bin/unity.o

./bin/tests: ./tests/tests.c ./bin/unity.o ./bin/list_rec.o
	gcc -Wall -Wextra ./bin/unity.o ./bin/list_rec.o ./tests/tests.c -o ./bin/tests

clean:
	rm ./bin/tests  
