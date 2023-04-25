#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // target not found
}

int main() {
    vector<int> arr = { 5, 7, 10, 15, 20, 25 };
    int target = 15;
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Found " << target << " at index " << index << endl;
    }
    else {
        cout << "Could not find " << target << " in array" << endl;
    }
    return 0;
}
