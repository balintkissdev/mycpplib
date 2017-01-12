.PHONY: test leak-check clean

CFLAGS=-g -Wall -std=c++98
INCLUDE= -I./include

# TODO: tidy and use wildcards
test:
	mkdir -p bin
	${CXX} ${CFLAGS} test/memory/UniquePtrTest.cpp ${INCLUDE} -o bin/UniquePtrTest && ./bin/UniquePtrTest
	${CXX} ${CFLAGS} test/container/ArrayListTest.cpp ${INCLUDE} -o bin/ArrayListTest && ./bin/ArrayListTest
	${CXX} ${CFLAGS} test/container/LinkedListTest.cpp ${INCLUDE} -o bin/LinkedListTest && ./bin/LinkedListTest

.PHONY: leak-check
leak-check:
	# TODO: check for valgrind
	${CXX} ${CFLAGS} ${SRC} ${INCLUDE} -o ${OBJ} && valgrind --leak-check=full --show-leak-kinds=all ./${OBJ}

#.PHONY: benchmark
#benchmark: TODO

clean:
	rm -rf bin
