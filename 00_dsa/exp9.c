#include <stdio.h>

// Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Key not found
}

// Fibonacci Search
int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int key, int n) {
    int fibMm2 = 0;    // (m-2)'th Fibonacci number
    int fibMm1 = 1;    // (m-1)'th Fibonacci number
    int fibM = fibMm2 + fibMm1;  // m'th Fibonacci number

    while (fibM < n) {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMm2, n - 1);

        if (arr[i] < key) {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        } else if (arr[i] > key) {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        } else {
            return i;
        }
    }

    if (fibMm1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1; // Key not found
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int quickPart(int arr[], int low, int high){
    int l = low, h = high;
    int pivot = arr[l],temp;
    while(l<h){
        do{
            l++;
        }
        while(pivot>=arr[l] && l<=h);
        do{
            h--;
        }
        while(pivot<arr[h] && h>=l);
        if(l<h){
            temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[h];
    arr[h] = temp;
    return h;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = quickPart(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi );
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Binary Search
    int binaryKey = 22;
    int binaryIndex = binarySearch(arr, 0, n - 1, binaryKey);
    printf("\nBinary Search: Element %d is at index %d\n", binaryKey, binaryIndex);

    // Fibonacci Search
    int fibonacciKey = 25;
    int fibonacciIndex = fibonacciSearch(arr, fibonacciKey, n);
    printf("Fibonacci Search: Element %d is at index %d\n", fibonacciKey, fibonacciIndex);

    // Selection Sort
    selectionSort(arr, n);
    printf("Selection Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Merge Sort
    mergeSort(arr, 0, n - 1);
    printf("Merge Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Quick Sort
    quickSort(arr, 0, n - 1);
    printf("Quick Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
