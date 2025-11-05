#include <stdio.h>

int indexSequentialSearch(int arr[], int n, int key, int blockSize) {
    int i, index = -1;

    // Step 1: Jump in blocks to find the range
    for (i = 0; i < n; i += blockSize) {
        if (arr[i] == key)
            return i;
        if (arr[i] > key)
            break;
    }

    // Step 2: Linear search in the previous block
    int start = i - blockSize;
    if (start < 0) start = 0;

    for (int j = start; j < n && j < i; j++) {
        if (arr[j] == key)
            return j;
    }

    return -1;
}

int main() {
    int arr[50], n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int blockSize = 3;
    int result = indexSequentialSearch(arr, n, key, blockSize);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found.\n");

    return 0;
}

