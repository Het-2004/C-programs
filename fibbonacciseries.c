#include <stdio.h>

void printFibonacci(int n);

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}

void printFibonacci(int n) {
    static int count = 0;
    static int first = 0;
    static int second = 1;

    if(count < n) {
        if(count <= 1)
            first = count;
        else {
            first = second;
            second = first + second;
        }
        printf("%d ", first);
        count++;
        printFibonacci(n);
    }
}
