
OMP_NUM_THREADS = 8

euler3d_omp_parallel: euler3d_omp_parallel.cpp
	g++ -O3 -Dblock_length=$(OMP_NUM_THREADS) -fopenmp euler3d_omp_parallel.cpp -o euler3d_omp_parallel
