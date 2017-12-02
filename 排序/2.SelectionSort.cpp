//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "swap.h"

using namespace std;

class Solution {
public:
    //  选择排序
    //  平均时间复杂度：n^2，最好情况：n^2，最坏情况：n^2，
    //  空间复杂度：1，
    //  不稳定排序
    static void SelectionSort(int *arr, int length) {
        if (checkPoint(arr)) {
            return;
        }

        for (int i = 0; i < length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr + i, arr + min);
        }
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    printArray(arr, length);
    s.SelectionSort(arr, length);
    printArray(arr, length);

    return 0;
};