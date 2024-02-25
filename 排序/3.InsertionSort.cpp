//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "Swap.h"

using namespace std;

class Solution {
public:
    //  插入排序
    //  平均时间复杂度：n^2，最好情况：n，最坏情况：n^2，
    //  空间复杂度：1，
    //  稳定排序
    static void InsertionSort(int *arr, int length) {
        if (pointIsNull(arr)) {
            return;
        }

        for (int i = 1; i < length; i++) {
            int j = i;
            int key = arr[j];

            for (; j - 1 >= 0 && arr[j - 1] > key; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = key;
        }
    }
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    printArray(arr, length);
    s.InsertionSort(arr, length);
    printArray(arr, length);

    return 0;
};