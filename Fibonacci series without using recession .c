#include <stdio.h>

int main() {
    int n, i, fib1 = 0, fib2 = 1, nextFib;

    printf("Enter the number of Fibonacci numbers you want: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 0; i < n; i++) {
        if (i <= 1) {
            nextFib = i;
        } else {
            nextFib = fib1 + fib2;
            fib1 = fib2;
            fib2 = nextFib;
        }
        printf("%d ", nextFib);
    }

    return 0;
}
