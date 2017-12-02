//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "swap.h"

using namespace std;

class Solution {
public:
    //  桶排序
    static void BucketSort(int *arr, int length) {
        if (checkPoint(arr)) {
            return;
        }

        int max = arr[0];
        for (int i = 1; i < length; i++) {
            max = max > arr[i] ? max : arr[i];
        }

        int *count;
        if ((count = (int *) malloc(sizeof(int) * max)) == NULL) {
            return;
        }

        memset(count, 0, max * sizeof(int));
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    s.BucketSort(arr, length);
    printArray(arr, length);
    printArray(arr, length);

    return 0;
};