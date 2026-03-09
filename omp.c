#include <stdio.h>
#include <time.h>
#include <omp.h>
int main() {
    int n;
    printf("Jep n (0-20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Input i pavlefshem!\n");
        return 1;
    }
    long long f = 1;
    double start = omp_get_wtime();   // fillimi i kohes
    #pragma omp parallel for reduction(*:f)
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    double end = omp_get_wtime();     // fundi i kohes
    printf("Faktoriali = %lld\n", f);
    printf("Koha: %f sekonda\n", end - start);
    return 0;
}
