#include <iostream>
using namespace std;

void mergesort(int arr[], int l, int r){
    if(l >= r) return;
    
    int m = l + (r - l) / 2;
    
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

int main(){
    int arr1[] = {12,11,13,5,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {38,27,43,3,9,82,10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    mergesort(arr1, 0, n1 - 1);
    mergesort(arr2, 0, n2 - 1);
    
    for (int i=0; i<n1; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n2; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}