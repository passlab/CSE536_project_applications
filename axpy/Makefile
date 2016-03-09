default: axpy_omp axpy_omp_task axpy_cilkplus_for axpy_cilkplus_spwan axpy_c++_thread  axpy_c++_async

axpy_omp: axpy_omp_parallel.c
	icc -O0 -openmp axpy_omp_parallel.c -o axpy_omp
        
axpy_omp_task: axpy_omp_task.c 
	icc -O0 -openmp axpy_omp_task.c -o axpy_omp-task

axpy_cilkplus_for: axpy_cilkplus_cilk_for.c
	icc -O0 axpy_cilkplus_cilk_for.c -o axpy_cilkplus-for

axpy_cilkplus_spwan: axpy_cilkplus_spawn.c
	icc -O0 axpy_cilkplus_spawn.c -o axpy_cilkplus-spawn

axpy_c++_thread: axpy_c++_thread.cpp
	icc -std=c++11 -pthread axpy_c++_thread.cpp -o axpyct

axpy_c++_async: axpy_c++_async.cpp
#	cc -std=c++11 -pthread axpy_c++_async.cpp -O0 axpycasync
	g++ -std=c++11 axpy_c++_async.cpp -lpthread -O0

clean:
	rm -rf ${OBJS} *.log
