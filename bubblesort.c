#include <stdio.h>

void bubbleSort(int arr[], int n) {
   for (int step = 0; step < n - 1; ++step) {
       for (int i = 0; i < n - step - 1; ++i) {
           if (arr[i] > arr[i + 1]) {
               // Swap arr[i] and arr[i+1]
               int temp = arr[i];
               arr[i] = arr[i + 1];
               arr[i + 1] = temp;
           }
       }
   }
}

void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

int main() {
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   bubbleSort(arr, n);
   printf("Sorted array: \n");
   printArray(arr, n);
   return 0;
}