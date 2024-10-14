#include <omp.h>
#include <iostream>
#include <iomanip>

static long num_steps = 1024l*1024*1024*2;
#define MIN_BLK 1024*1024*256

double sum = 0;

void pi_r(long Nstart, long Nfinish, double step) {
    long i;
    for (i = Nstart; i < Nfinish; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x); 
    }
}

int main () {
    long i;
    double step, pi;
    double init_time, final_time;
    
    step = 1.0 / (double) num_steps;
    init_time = omp_get_wtime();
    
    #pragma omp parallel for
    for (i = 0; i < num_steps; i += MIN_BLK) {
        pi_r(i, i + MIN_BLK, step);
    }

    pi = step * sum;
    final_time = omp_get_wtime() - init_time;

    std::cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
}
