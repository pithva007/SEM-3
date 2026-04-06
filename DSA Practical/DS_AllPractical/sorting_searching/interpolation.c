#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0,high=size-1;
    while(low<=high && target>=arr[low] && target<=arr[high]) {
        int pos = low +((target - arr[low]) *(high - low))/(arr[high] - arr[low]);
        if(arr[pos]==target)
            return pos;
        if(arr[pos]<target)
            low=pos+1;
        else
            high=pos-1;
    }
    return -1;
}

int main() {
    int arr[100],n,target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &target);

    int index=interpolationSearch(arr,n,target);
    if (index!=-1)
        printf("Element found at position %d\n", index + 1);
    else
        printf("Element not found\n");
    return 0;
}