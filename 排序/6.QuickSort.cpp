//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "swap.h"

using namespace std;

class Solution {
public:
    //  快速排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n^2，
    //  空间复杂度：Log2N ~ LogN，
    //  不稳定排序
    static void QuickSort(int *arr, int length) {
        if (checkPoint(arr)) {
            return;
        }

        int low = 0;
        int high = length - 1;
        quickSort(low, high, arr);
    };
private:
    static void quickSort(int low, int high, int *arr) {
        if (low < high) {
            int first = low;
            int last = high;
            int key = arr[first];

            while (first < last) {
                while (first < last && arr[last] >= key) {
                    --last;
                }
                arr[first] = arr[last];
                while (first < last && arr[first] <= key) {
                    ++first;
                }
                arr[last] = arr[first];
            }
            arr[first] = key;

            quickSort(low, first - 1, arr);
            quickSort(first + 1, high, arr);
        }
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    printArray(arr, length);
    s.QuickSort(arr, length);
    printArray(arr, length);

    return 0;
};