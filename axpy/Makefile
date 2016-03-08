default: axpy_omp axpy_cilkplus axpy_c++_mthread

axpy_omp_parallel: axpy_omp_parallel.c
	icc -O0 -openmp axpy_omp_parallel.c -o axpy_omp-icc
        
axpy_omp_task: axpy_omp_task.c 
	icc -O0 -openmp axpy_omp_task.c -o axpy_omp-icc

axpy_cilkplus_for: axpy_cilkplus_cilk_for.c
	icc -O0 axpy_cilkplus_cilk_for.c -o axpy_cilkplus-icc

axpy_cilkplus_spwan: axpy_cilkplus_spawn.c
	icc -O0 axpy_cilkplus_spawn.c -o axpy_cilkplus-icc

axpy_c++_thread: axpy_c++_thread.cpp
	icc -std=c++11 -pthread axpy_c++_thread.cpp -O0 axpyct

axpy_c++_async: axpy_c++_async.cpp
#	cc -std=c++11 -pthread axpy_c++_async.cpp -O0 axpyct
	g++ -std=c++11 axpy_c++_async.cpp -lpthread -O0

clean:
	rm -rf ${OBJS} *.log
