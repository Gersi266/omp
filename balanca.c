#include <stdio.h>
#include <omp.h>
int main() {
    int x = 10;
    int d[10] = {100, 50, 200, 400};
    int balance = 1000;
    #pragma omp parallel for reduction(+:balance)
    for (int i = 0; i < x; i++) {
        balance += d[i];
    }
    printf("Balance totale: %d\n", balance);
    return 0;
}
