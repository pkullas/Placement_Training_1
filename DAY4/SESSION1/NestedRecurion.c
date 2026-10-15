#include <stdio.h>

int A(int n);

int A(int n) {
    if (n > 100) {
        return n - 10;
    }
    return A(A(n + 11));
}

int main() {
    printf("%d\n", A(95));
    return 0;
}