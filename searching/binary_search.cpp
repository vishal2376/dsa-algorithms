#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // target not found
}

int main() {
    vector<int> arr = { 2, 4, 7, 8, 10, 13, 15, 19 };
    int target = 8;
    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Found " << target << " at index " << index << endl;
    }
    else {
        cout << "Could not find " << target << " in array" << endl;
    }
    return 0;
}
