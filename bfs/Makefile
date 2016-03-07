# C compiler
CC = g++
ICC = icc
CC_FLAGS = -g -fopenmp -O0

all: bfs 

bfs: bfs.cpp 
	$(ICC) $(CC_FLAGS) bfs.cpp -o bfs 

clean:
	rm -f bfs result.txt
