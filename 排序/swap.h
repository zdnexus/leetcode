//
// Created by 钟东 on 17/11/28.
//

#ifndef LEETCODE_SWAP_H
#define LEETCODE_SWAP_H

#include <iostream>

using namespace std;

static bool checkPoint(int *p) {
    return p == NULL;
}

static void cinArr(int *arr, int length) {
    srand((unsigned int) time(0));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 10 + 1;
    }
};

static void printArray(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
};

static void swap(int *p1, int *p2) {
    if (p1 != p2) {
        *p1 = *p1 ^ *p2;
        *p2 = *p1 ^ *p2;
        *p1 = *p1 ^ *p2;
    }
};

#endif LEETCODE_SWAP_H
