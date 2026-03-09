#include <stdio.h>
#include <gmp.h>
#include <omp.h>
int main() {
    int n;
    printf("Jep n: ");
    scanf("%d", &n);
    mpz_t fact;
    mpz_init_set_ui(fact, 1);
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        mpz_t local;
        mpz_init_set_ui(local, 1);
        #pragma omp for nowait
        for (int i = 2; i <= n; i++)
            mpz_mul_ui(local, local, i);
        #pragma omp critical
        {
            mpz_mul(fact, fact, local);
        }
        mpz_clear(local);
    }
    double end = omp_get_wtime();
    gmp_printf("Faktoriali = %Zd\n", fact);
    printf("Koha parallel: %f sekonda\n", end - start);
    mpz_clear(fact);
    return 0;
}
