# C compiler
CC = g++
ICC = icc
CC_FLAGS = -g -fopenmp -O0

all: hotspot  

hotspot: hotspot_openmp.cpp Makefile 
	$(ICC) $(CC_FLAGS) hotspot_openmp.cpp -o hotspot 

clean:
	rm -f hotspot output.out
