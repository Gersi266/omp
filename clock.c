#include <stdio.h>
#include <time.h>
#include <gmp.h>
int main() {
    int n;
    printf("Jep n: ");
    scanf("%d", &n);
    mpz_t fact;
    mpz_init_set_ui(fact, 1);
    clock_t start = clock();
    for (int i = 2; i <= n; i++)
        mpz_mul_ui(fact, fact, i);
    clock_t end = clock(); 
    gmp_printf("Faktoriali = %Zd\n", fact);
    printf("Koha serial: %f sekonda\n", (double)(end - start) / CLOCKS_PER_SEC);
    mpz_clear(fact);
    return 0;
}
