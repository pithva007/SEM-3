#include <iostream>
using namespace std;

// Merge two sorted parts of array
void merge(int arr[], int l, int m, int r) {
    int i = l;       
    int j = m + 1;   
    int k = 0;       
    
    int temp[r - l + 1]; 

    while(i <= m && j <= r) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= m) {
        temp[k++] = arr[i++];
    }

    while(j <= r) {
        temp[k++] = arr[j++];
    }

    for(int x = 0; x < k; x++) {
        arr[l + x] = temp[x];
    }
}

// Main Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);     
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r);      
    }
}

// Print array
void print(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {8, 3, 2, 7, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    print(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted:   ";
    print(arr, n);

    return 0;
}
