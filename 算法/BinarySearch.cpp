//
// Created by zdnexus on 17/11/27.
//

#include <iostream>

using namespace std;

void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    static int BinarySearch(int target, int *arr, int length) {
        cout << sizeof(arr) << endl;
        cout << sizeof(arr[0]) << endl;

        int low = 0;
        int high = length;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (arr[mid] > target) {
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    int arr[10] = {1, 3, 6, 13, 24, 35, 56, 78, 90, 96};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    int res = s.BinarySearch(target, arr, length);

    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;

    cout << res << endl;

    return 0;
}

