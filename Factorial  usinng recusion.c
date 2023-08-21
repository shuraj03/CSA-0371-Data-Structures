#include <stdio.h>

int factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int number = 5;
    int result = factorial_recursive(number);
    printf("The factorial of %d is %d\n", number, result);
    return 0;
}
