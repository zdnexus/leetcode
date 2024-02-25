//
// Created by 钟东 on 17/11/20.
//

#include <iostream>
#include "Swap.h"

using namespace std;

class Solution {
public:
    //  堆排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n * Log2N，
    //  空间复杂度：LogN，
    //  不稳定排序
    static void HeapSort(int *arr, int length) {
        int size = length - 1;

        for (int i = length / 2 - 1; i >= 0; i--) {
            minHeap(arr, i, size);
        }
        for (int i = size; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            minHeap(arr, 0, i - 1);
        }
    };
private:
    static void minHeap(int *arr, int current, int size) {
        if (pointIsNull(arr)) {
            return;
        }

        int left = 2 * current + 1;
        int key = arr[current];

        for (; left <= size; left = left * 2 + 1) {
            int right = left + 1;

            if (right <= size && arr[right] > arr[left]) {
                left = right;
            }
            if (key >= arr[left]) {
                break;
            } else {
                arr[current] = arr[left];
                arr[left] = key;
                current = left;
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
    s.HeapSort(arr, length);
    printArray(arr, length);

    return 0;
};