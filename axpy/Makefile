
default: axpy_omp axpy_cilkplus

axpy_omp: axpy_omp.c
	icc -O0 -openmp axpy_omp.c -o axpy_omp-icc

axpy_cilkplus: axpy_cilkplus.c
	icc -O0 axpy_cilkplus.c -o axpy_cilkplus-icc

clean:
	rm -rf ${OBJS} *.log
