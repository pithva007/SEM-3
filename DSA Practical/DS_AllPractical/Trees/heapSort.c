#include <stdio.h>

void heapify(int a[], int n, int i) {
    int max = i;      
    int left = 2*i + 1;  
    int right = 2*i + 2; 

    if(left<n && a[left]>a[max]){
        max = left;
    }
        
    if(right<n && a[right]>a[max]){
        max = right;
    }
    
    if(max != i){
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a, n, max);
    }
}

void heapSort(int a[], int n) {
    for(int i = n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
    for(int i= n-1; i>=0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
        

    heapSort(a,n);
    printf("Sorted array in ascending order:\n");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }printf("\n");
    return 0;
}
