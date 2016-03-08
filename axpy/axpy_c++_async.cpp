// example for thread::join
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::seconds
#include <future>
#include <pthread.h>
#include <thread> 
#include <stdlib.h> 
#include <sys/timeb.h>
//#define REAL REAL

using namespace std;

#define NUM_THREADS 5
#define vector_length 102400

#define BASE 1000
#define REAL float

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
}

//===========================async-future

void axpy_async_task(int N, REAL *Y, REAL *X, REAL a) {

 if (N<=BASE) {
       int i;
       for (i = 0; i < N; ++i)
          Y[i] += a * X[i];
            } else {

   std::future<void> f1  = std::async(std::launch::async,axpy_async_task,N/2, Y, X, a);
        axpy_async_task(N-N/2, Y+N/2, X+N/2, a);
   f1.get();     
                   }
    }

//===========================          
int main() 
{
 int N=vector_length;
REAL X[N];
REAL Y[N];
REAL a=0.1234;
double elapsed;
double elapsed_dist;

elapsed=read_timer();
 axpy_async_task( N, Y, X, a);
elapsed=(read_timer() - elapsed); 

    printf("======================================================================================================\n");
    printf("\tAXPY: Y[N] = Y[N] + a*X[N], N=%d, %d tasks for dist\n", N, NUM_THREADS);
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Performance:\t\tRuntime (ms)\t MFLOPS \t\tError (compared to base)\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("axpy_c++_async:\t\t%4f\t%4f \t\t%g\n", elapsed * 1.0e3, (2.0 * N) / (1.0e6 * elapsed), check(Y, Y, N));
  


return 0;
}
