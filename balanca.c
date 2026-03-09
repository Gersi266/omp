#include <stdio.h>
#include <omp.h>
int main() {
    int x = 4;
    int d[] = {100, 50, 200, 400};
    int balance = 1000;
    #pragma omp parallel for reduction(+:balance)
    for (int i = 0; i < x; i++) {
        int tid = omp_get_thread_num();
        printf("Thread %d: balance perpara = %d, shtojme d[%d] = %d\n",
               tid, balance, i, d[i]);
        balance += d[i];
        printf("Thread %d: balance perfundimtare = %d\n", tid, balance);
    }
    printf("Total balance: %d\n", balance);
    return 0;
}
