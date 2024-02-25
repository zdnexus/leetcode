//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "Swap.h"

using namespace std;

class Solution {
public:
    //  归并排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n * Log2N，
    //  空间复杂度：n，
    //  稳定排序
    static void MergeSort(int *arr, int length) {
        if (pointIsNull(arr)) {
            return;
        }

        int low = 0;
        int high = length - 1;
        int *temp = (int *) malloc(sizeof(int) * length);
        mergeSort(low, high, arr, temp);
        free(temp);
    };
private:
    static void mergeSort(int low, int high, int *arr, int *temp) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(low, mid, arr, temp);
            mergeSort(mid + 1, high, arr, temp);
            mergeArray(low, mid, high, arr, temp);
        }
    };

    static void mergeArray(int low, int mid, int high, int *arr, int *temp) {
        int first = low;
        int center = mid;
        int centerPlusOne = mid + 1;
        int last = high;
        int i = 0;

        while (first <= center && centerPlusOne <= last) {
            if (arr[first] <= arr[centerPlusOne]) {
                temp[i++] = arr[first++];
            } else {
                temp[i++] = arr[centerPlusOne++];
            }
        }

        while (first <= center) {
            temp[i++] = arr[first++];
        }

        while (centerPlusOne <= last) {
            temp[i++] = arr[centerPlusOne++];
        }

        for (int j = 0; j < i; j++) {
            arr[low + j] = temp[j];
        }
    };
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);

    cinArr(arr, length);
    printArray(arr, length);
    s.MergeSort(arr, length);
    printArray(arr, length);

    return 0;
};