// example for thread::join
#include <stdlib.h>
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::seconds
#include <pthread.h>
#include <thread>
#include <sys/timeb.h>
#include <math.h>
#include <stdio.h>
#include <future>
#include <vector>

using namespace std;

/* read timer in second */
double read_timer() {
    struct timeb tm;
    ftime(&tm);
    return (double) tm.time + (double) tm.millitm / 1000.0;
}

/* read timer in ms */
double read_timer_ms() {
    struct timeb tm;
    ftime(&tm);
    return (double) tm.time * 1000.0 + (double) tm.millitm;
}
#define NUM_THREADS 64 
#define vector_length 102400
#define REAL float
std::vector <std::future<void>> f(NUM_THREADS);


void init(REAL *A, int N){
int i;
for (i=0; i<N; i++) {
A[i]= (double) drand48();
}
}


double check(REAL A[], REAL B[], int N) {
    int i;
    double sum = 0.0;
    for (i = 0; i < N; i++) {
        sum += A[i] - B[i];
    }
    return sum;
int num_runs = 10;
}

//===========================
void axpy_cmth(int start,int end, REAL *Y, REAL *X, REAL a) {
    int i;
    for (i = start; i <end; ++i)
        Y[i] += a * X[i];     
     }

//void axpy_cmth(int N, REAL *Y, REAL *X, REAL a, int NUM_THREADS);

//===========================          
int main(int argc, char * argv[]) 
{
int  N=vector_length;
int threadno = NUM_THREADS;
double elapsed;
double elapsed_dist;

if (argc < 2) {
  fprintf(stderr, "Usage: axpy <n> [<#threads(%d)>] (n should be dividable by #threads)\n", threadno);
exit(1);
 }
 N = atoi(argv[1]);
 if (argc > 2) threadno = atoi(argv[2]);
REAL a=0.1234;

//printf("%d: %d\n", N, NUM_THREADS);


srand48((1 << 12));
REAL *X =(REAL *) malloc(sizeof(REAL)*N);
REAL *Y = (REAL *) malloc(sizeof(REAL)*N);
//REAL X[N];
//REAL Y[N];
    init(X, N);
    init(Y, N);



//std::thread thread[ threadno ];
elapsed=read_timer();
int i,j;
for(i=0; i<threadno;++i)
{       int tid = i;
        int i_end,i_start, Nt;
        Nt = N/threadno;
        i_start = tid*Nt;
        i_end = (tid+1)*Nt; 
        //printf("creating thread: %d\n", i);
        f[i]=std::async(std::launch::async,axpy_cmth,i_start,i_end,(REAL *)Y, (REAL *)X, a); 
}      
for(j=0;j<threadno;++j)
 f[j].get();// join the first thread 

elapsed=(read_timer() - elapsed); 

    printf("======================================================================================================\n");
  printf("\tAXPY: Y[N] = Y[N] + a*X[N], N=%d, %d tasks for dist\n", N, threadno);
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Performance:\t\tRuntime (ms)\t MFLOPS \t\tError (compared to base)\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("axpy_base:\t\t%4f\t%4f \t\t%g\n", elapsed * 1.0e3, (2.0 * N) / (1.0e6 * elapsed), check(Y, Y, N));
  


return 0;
}
