//
// Created by 钟东 on 17/11/20.
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
private:
    typedef struct node {
        int n;
        struct node *next;
    } Node;

    static void swap(int *a, int *b) {
        if (a != b) {
            *a = *a ^ *b;
            *b = *a ^ *b;
            *a = *a ^ *b;
        }
    };

    //  归并排序
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

    //  快速排序
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

    // 堆排序
    static void minHeap(int *arr, int current, int size) {
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
public:
    //  冒泡排序
    //  平均时间复杂度：n^2，最好情况：n，最坏情况：n^2，空间复杂度：1，稳定排序
    static void BubbleSort(int *arr, int length) {
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

    //  选择排序
    //  平均时间复杂度：n^2，最好情况：n^2，最坏情况：n^2，空间复杂度：1，不稳定排序
    static void SelectionSort(int *arr, int length) {
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

    //  插入排序
    //  平均时间复杂度：n^2，最好情况：n，最坏情况：n^2，空间复杂度：1，稳定排序
    static void InsertionSort(int *arr, int length) {
        for (int i = 1; i < length; i++) {
            int j = i;
            int key = arr[j];

            for (; j - 1 >= 0 && arr[j - 1] > key; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = key;
        }
    }

    //  希尔排序
    //  平均时间复杂度：n * Log2N，最好情况：，最坏情况：n^1.5，空间复杂度：1，不稳定排序
    static void ShellSort(int *arr, int length) {
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

    //  归并排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n * Log2N，空间复杂度：n，稳定排序
    static void MergeSort(int *arr, int length) {
        int low = 0;
        int high = length - 1;
        int *temp = (int *) malloc(sizeof(int) * length);
        mergeSort(low, high, arr, temp);
        free(temp);
    };

    //  快速排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n^2，空间复杂度：Log2N ~ LogN，不稳定排序
    static void QuickSort(int *arr, int length) {
        int low = 0;
        int high = length - 1;
        quickSort(low, high, arr);
    };

    //  堆排序
    //  平均时间复杂度：n * Log2N，最好情况：n * Log2N，最坏情况：n * Log2N，空间复杂度：LogN，不稳定排序
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

    //  计数排序
    //  平均时间复杂度：n + k，最好情况：n + k，最坏情况：n + k，空间复杂度：k，稳定排序
    static void CountingSort(int *arr, int length) {
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

    //  桶排序
    static void BucketSort(int *arr, int length) {
        if (arr == NULL) {
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

        int space = (max + 10) / 10;
        for (int i = 0; i < length; i++) {

        }
    };

    //  基数排序
    static void RadixSort(int *arr, int length) {
        int *temp;
        if ((temp = (int *) malloc(sizeof(int) * length)) == NULL) {
            return;
        }
        memset(temp, 0, sizeof(int) * length);
    }
};

int main() {
    Solution s;
    int arr[10];
    int length = sizeof(arr) / sizeof(arr[0]);
    srand((unsigned int) time(0));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 10 + 1;
    }

    printArray(arr, length);

//    s.BubbleSort(arr, length);
//    s.SelectionSort(arr, length);
//    s.InsertionSort(arr, length);
//    s.ShellSort(arr, length);
//    s.MergeSort(arr, length);
//    s.QuickSort(arr, length);
//    s.HeapSort(arr, length);
//    s.CountingSort(arr, length);
    s.BucketSort(arr, length);

    printArray(arr, length);

    return 0;
}