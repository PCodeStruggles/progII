all: main

array_ops: ./src/array_ops.c ./include/array_ops.h
	gcc -Wall -Wextra -c ./src/array_ops.c -o ./bin/array_ops.o

main: array_ops
	gcc -Wall -Wextra ./bin/array_ops.o ./src/main.c -o ./bin/main

run:
	./bin/main

clean:
	rm ./bin/*
