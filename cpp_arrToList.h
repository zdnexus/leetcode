//
// Created by Administrator on 2017/1/6 0006.
//

#ifndef LEETCODE_CPP_ARRTOLIST_H
#define LEETCODE_CPP_ARRTOLIST_H

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void printList(struct ListNode *list) {
    for (struct ListNode *p = list; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

struct ListNode *arrToList(int *arr, int length) {
    if (arr == NULL) {
        return NULL;
    }
    struct ListNode *list = NULL;
    struct ListNode *currentNode = NULL;
    for (int i = 0; i < length; ++i) {
        struct ListNode *newNode = new ListNode(arr[i]);
        if (list == NULL) {
            list = newNode;
        } else {
            currentNode->next = newNode;
        }
        currentNode = newNode;
    }
    printList(list);
    return list;
}

#endif //LEETCODE_CPP_ARRTOLIST_H
