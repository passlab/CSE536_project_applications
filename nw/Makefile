# C compiler
CC = g++
ICC = icc
CC_FLAGS = -g -O0 -fopenmp

all: needle 

needle: 
	$(ICC) $(CC_FLAGS) needle.cpp -o needle 

clean:
	rm -f needle result.txt 
