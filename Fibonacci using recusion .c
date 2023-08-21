#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers you want: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}
