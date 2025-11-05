#include <stdio.h>
int main() {
    int arr[50], n, key, low, high, mid, found=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter %d sorted elements:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter element to search: ");
    scanf("%d",&key);
    low=0; high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){ found=1; break; }
        else if(arr[mid]>key) high=mid-1;
        else low=mid+1;
    }
    if(found) printf("Found at position %d\n",mid+1);
    else printf("Not found\n");
    return 0;
}

