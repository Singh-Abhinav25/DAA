#include <iostream>
using namespace std;

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){

    int arr[] = {4,2,6,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    
    for (int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}