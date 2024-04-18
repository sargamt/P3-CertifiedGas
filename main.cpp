#include <iostream>
#include <vector>

#include "quickSort.cpp"

using namespace std;

int main() {
    // Testing quickSort...
    vector<int> nums{43, 5, 12, 34, 53, 87, 10, 11, 9, 8};
    int n = nums.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    quickSort(nums, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
