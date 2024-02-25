//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "Swap.h"

using namespace std;

class Solution {
public:
    //  计数排序
    //  平均时间复杂度：n + k，最好情况：n + k，最坏情况：n + k，
    //  空间复杂度：k，
    //  稳定排序
    static void CountingSort(int *arr, int length) {
        if (pointIsNull(arr)) {
            return;
        }

        int max = arr[0];
        for (int i = 1; i < length; i++) {
            max = max > arr[i] ? max : arr[i];
        }
        ++max;

        int *count;
        if ((count = (int *) malloc(sizeof(int) * max)) == NULL) {
            return;
        }
        memset(count, 0, max * sizeof(int));
        for (int i = 0; i < length; i++) {
            count[arr[i]]++;
        }
        for (int i = 1; i < max; i++) {
            count[i] = count[i] + count[i - 1];
        }

        int *temp;
        if ((temp = (int *) malloc(sizeof(int) * length)) == NULL) {
            return;
        }
        for (int i = length - 1; i >= 0; i--) {
            temp[--count[arr[i]]] = arr[i];
        }

        for (int i = 0; i < length; i++) {
            arr[i] = temp[i];
        }

        free(count);
        free(temp);
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    s.CountingSort(arr, length);
    printArray(arr, length);
    printArray(arr, length);

    return 0;
};