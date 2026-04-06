#include<stdio.h>

int main(){
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    int a[n];
    for(int i =0; i<n; i++){
        printf("Enter Elements %d: " ,i);
        scanf("%d", &a[i]);
    }
    int target;
    printf("Enter Number to Find");
    scanf("%d", &target);

    int ok = 0;
    for(int i =0; i<n; i++){
        if(a[i] == target){
            printf("Element Found at Index %d", i);
            ok = 1;
            break;
        }
    }
    if(ok == 0){
        printf("Element Does not present in array");
    }
    
}