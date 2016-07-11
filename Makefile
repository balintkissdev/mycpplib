SRC=src/Main.cpp src/ArrayList.cpp 

all:
	g++ -g -Wall -std=c++98 ${SRC} -o Libtest
