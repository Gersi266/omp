#include <stdio.h>
#include <omp.h>
int main() {
    int n;
    printf("Jepni numrin e elementeve: ");
    scanf("%d", &n);
    int a[n];
    printf("Jepni elementet e vektorit:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int max = a[0];
    #pragma omp parallel for reduction(max:max)
    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    printf("Elementi maksimal eshte: %d\n", max);
    return 0;
}
