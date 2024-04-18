#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high]; // Chooses the last element of the given array as the pivot
    int small = low - 1; // Index of the smaller element beginning before the array to ensure the first element is smaller than the pivot

    for(int i = low; i < high; i++){
        // If the current input is smaller than or equal to the pivot the index of where the pivot will go increases and the element being checked is placed into the left side of where the pivot will go
        if(arr[i] <= pivot){
            small++;
            swap(arr[small], arr[i]);
        }
    }
    swap(arr[small + 1], arr[high]); // Swaps the pivot with the element that is in between the ones less than the pivot and greater pivots
    return small + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        // Finds the partition index
        int splitIndex = partition(arr, low,high);

        // Recursively calls quick sort to then sort both sides of the partition
        quickSort(arr, low, splitIndex-1);
        quickSort(arr, splitIndex + 1, high);
    }
}