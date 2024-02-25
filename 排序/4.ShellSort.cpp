//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "Swap.h"

using namespace std;

class Solution {
public:
    //  希尔排序
    //  平均时间复杂度：n * Log2N，最好情况：，最坏情况：n^1.5，
    //  空间复杂度：1，
    //  不稳定排序
    static void ShellSort(int *arr, int length) {
        if (pointIsNull(arr)) {
            return;
        }

        for (int gap = length / 2; gap != 0; gap /= 2) {
            for (int i = 0; i < length; i++) {
                for (int j = i + gap; j < length; j += gap) {
                    if (arr[j] < arr[i]) {
                        swap(arr + i, arr + j);
                    }
                }
            }
        }
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    printArray(arr, length);
    s.ShellSort(arr, length);
    printArray(arr, length);

    return 0;
};