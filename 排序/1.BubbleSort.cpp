//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "swap.h"

using namespace std;

class Solution {
public:
    //  冒泡排序
    //  平均时间复杂度：n^2，最好情况：n，最坏情况：n^2，
    //  空间复杂度：1，
    //  稳定排序
    static void BubbleSort(int *arr, int length) {
        if (checkPoint(arr)) {
            return;
        }

        for (int i = 0; i < length - 1; i++) {
            bool flag = false;

            for (int j = 0; j + 1 < length - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr + j, arr + j + 1);
                    flag = true;
                }
            }
            if (!flag) {
                break;
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
    s.BubbleSort(arr, length);
    printArray(arr, length);

    return 0;
};