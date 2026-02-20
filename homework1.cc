#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

int main() {
    srand(time(0));
    system("mkdir -p /Users/admin/HW1/Homework1/results");
    ofstream f("/Users/admin/HW1/Homework1/results/pi_monte_carlo_results.csv");
    f << "N,pi_estimated,accuracy,execution_time_sec,time_per_point\n";

    long long n[] = {1000000, 10000000, 100000000, 1000000000, 10000000000LL, 100000000000LL};
    
    for (int k = 0; k < 6; k++) {
        long long N = n[k];
        cout << "N = " << N << endl;
        
        clock_t t1 = clock();
        long long inside = 0;
        
        for (long long i = 0; i < N; i++) {
            double x = (double)rand() / RAND_MAX * 2 - 1;
            double y = (double)rand() / RAND_MAX * 2 - 1;
            if (x*x + y*y <= 1)
                inside++;
        }
        
        double pi_est = 4.0 * inside / N;
        double sec = (double)(clock() - t1) / CLOCKS_PER_SEC;
        f << N << "," << pi_est << "," << fabs(pi_est - 3.14159265358979) << "," << sec << "," << sec/N << "\n";
        cout << "  pi = " << pi_est << "  час = " << sec << " с" << endl;
    }
    cout << "\nГотово! Результати в /Users/admin/HW1/Homework1/results/pi_monte_carlo_results.csv" << endl;
    return 0;
}
// final version