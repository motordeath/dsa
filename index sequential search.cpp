#include <stdio.h>

int indexSequentialSearch(int arr[], int n, int x, int blockSize) {
    int indexTable[50], indexPos[50], k = 0;

    for (int i = 0; i < n; i += blockSize) {
        indexTable[k] = arr[i];
        indexPos[k] = i;
        k++;
    }

    int blockIndex = -1;
    for (int i = 0; i < k; i++) {
        if (x <indexTable[i]) break;
        blockIndex = indexPos[i];
    }

    if (blockIndex == -1) return -1;

  for (int i = blockIndex; i <blockIndex + blockSize && i<n; i++)
        if (arr[i] == x) return i;

    return -1;
}

int main() {
    int n, x, blockSize;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    printf("Enter block size: ");
    scanf("%d", &blockSize);

    int pos = indexSequentialSearch(arr, n, x, blockSize);

    if (pos != -1)
        printf("Element %d found at index %d\n", x, pos);
    else
        printf("Element %d not found\n", x);

    return 0;
}

