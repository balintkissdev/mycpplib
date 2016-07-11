CFLAGS=-g -Wall -Wno-sign-compare -std=c++98
INCLUDE= -I./include
SRC=test/TestSuite.cpp 

.PHONY: test
test:
	g++ ${CFLAGS} ${SRC} ${INCLUDE} -o Libtest && ./Libtest
	rm -f Libtest
