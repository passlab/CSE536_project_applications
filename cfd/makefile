OMP_NUM_THREADS = 8
MIC_OMP_NUM_THREADS = 216

all: euler3d_omp_parallel 

euler3d_omp_parallel: euler3d_omp_parallel.cpp 
	icc -O0 -Dblock_length=$(OMP_NUM_THREADS) -openmp euler3d_omp_parallel.cpp -o euler3d_omp_parallel

clean:
	rm -f euler3d_omp_parallel density density_energy momentum

