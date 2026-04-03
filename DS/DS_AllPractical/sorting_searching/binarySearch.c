#include <stdio.h>

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i<n; i++){
        printf("Enter Element %d: ",i);
        scanf("%d", &a[i]);
    }

    int target;
    printf("Enter Number to Find: ");
    scanf("%d",&target);

    int ok = 0;
    int st = 0,end = n-1;

    
    while(st<=end){
        int mid = (st+end)/2;
        if(a[mid]==target){
            ok = 1;
            printf("Element found at index %d\n", mid);
            break;
        }else if(a[mid]<target){
            st = mid+1;
        } else {
            end = mid-1;
        }
    }

    if(ok == 0){
        printf("Element does not exist in array\n");
    }

    return 0;
}
