# main: ./tests/test_intLinkedListSortedSetADT
main: ./tests/unityTestsSuite
	./tests/unityTestsSuite

./bin/intLinkedListSortedSetADT.o: ./src/intLinkedListSortedSetADT.c
	gcc -Wall -Wextra -c ./src/intLinkedListSortedSetADT.c -o ./bin/intLinkedListSortedSetADT.o


./bin/unity.o: ./unity/unity.c ./unity/unity.h
	gcc -Wall -Wextra -c ./unity/unity.c -o ./bin/unity.o

./tests/unityTestsSuite: ./tests/unityTestsSuite.c ./bin/unity.o ./bin/intLinkedListSortedSetADT.o
	gcc -Wall -Wextra ./bin/unity.o ./bin/intLinkedListSortedSetADT.o ./tests/unityTestsSuite.c -o ./tests/unityTestsSuite


#./tests/test_intLinkedListSortedSetADT: ./bin/intLinkedListSortedSetADT.o
#	gcc -Wall -Wextra  ./bin/intLinkedListSortedSetADT.o ./tests/test_intLinkedListSortedSetADT.c -o ./tests/test_intLinkedListSortedSetADT

run:
	./tests/unityTestsSuite

clean:
	rm ./tests/unityTestsSuite
