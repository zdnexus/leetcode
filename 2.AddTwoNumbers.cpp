//
// Created by 钟东 on 2017/1/4 0004.
//
#include<iostream>
#include "cpp_arrToList.h"

using namespace std;

class Solution {
public:
    // 方法一
    struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            struct ListNode *list = NULL;//链表表头
            struct ListNode *currentNode = NULL;//链表追踪节点
            int numExtra = 0;//相加超出10的数字
            while (l1 && l2) {
                int sum = l1->val + l2->val + numExtra;
                struct ListNode *newNode = new ListNode(sum % 10);
                numExtra = sum / 10;
                if (list == NULL) {
                    list = newNode;
                } else {
                    currentNode->next = newNode;
                }
                currentNode = newNode;
                l1 = l1->next;
                l2 = l2->next;
            }
            struct ListNode *listExtra = (l1) ? l1 : l2;
            while (listExtra) {
                int sum = listExtra->val + numExtra;
                struct ListNode *newNode = new ListNode(sum % 10);
                numExtra = sum / 10;
                currentNode->next = newNode;//这里的currentNode绝对不是空指针
                currentNode = newNode;
                listExtra = listExtra->next;
            }
            if (numExtra) {
                struct ListNode *newNode = new ListNode(numExtra);
                currentNode->next = newNode;
            }
            return list;
        }
    };

    // 方法一(v2)
    struct ListNode *addTwoNumbers_1v2(struct ListNode *l1, struct ListNode *l2) {
        struct ListNode *list = NULL;//链表表头
        struct ListNode *currentNode = NULL;//链表追踪节点
        int numExtra = 0;//相加超出10的数字
        while (l1 || l2) {
            int sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val + numExtra;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val + numExtra;
                l1 = l1->next;
            } else {
                sum = l2->val + numExtra;
                l2 = l2->next;
            }
            struct ListNode *newNode = new ListNode(sum % 10);
            numExtra = sum / 10;
            if (list == NULL) {
                list = newNode;
            } else {
                currentNode->next = newNode;
            }
            currentNode = newNode;
        }
        if (numExtra) {
            struct ListNode *newNode = new ListNode(numExtra);
            currentNode->next = newNode;
        }
        return list;
    };

    // 方法一(v3)
    struct ListNode *addTwoNumbers_1v3(struct ListNode *l1, struct ListNode *l2) {
        struct ListNode *list = NULL;//链表表头
        struct ListNode *currentNode = NULL;//链表追踪节点
        int numExtra = 0;//相加超出10的数字
        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + numExtra;
            struct ListNode *newNode = new ListNode(sum % 10);
            numExtra = sum / 10;
            if (list == NULL) {
                list = newNode;
            } else {
                currentNode->next = newNode;
            }
            currentNode = newNode;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if (numExtra) {
            struct ListNode *newNode = new ListNode(numExtra);
            currentNode->next = newNode;
        }
        return list;
    };

    // 方法一(v4)
    struct ListNode *addTwoNumbers_1v4(struct ListNode *l1, struct ListNode *l2) {
        struct ListNode *list = NULL;//链表表头
        struct ListNode *currentNode = NULL;//链表追踪节点
        int numExtra = 0;//相加超出10的数字
        while (l1 || l2 || numExtra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + numExtra;
            struct ListNode *newNode = new ListNode(sum % 10);
            numExtra = sum / 10;
            if (list == NULL) {
                list = newNode;
            } else {
                currentNode->next = newNode;
            }
            currentNode = newNode;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return list;
    }

    // 方法二
    struct ListNode *addTwoNumbers_2(struct ListNode *l1, struct ListNode *l2, int numExtra) {
        struct ListNode *newNode = new ListNode(0);
        if (l1 && l2) {
            int sum = l1->val + l2->val + numExtra;
            newNode->val = sum % 10;
            newNode->next = addTwoNumbers_2(l1->next, l2->next, sum / 10);
        } else if (l1) {
            int sum = l1->val + numExtra;
            newNode->val = sum % 10;
            newNode->next = addTwoNumbers_2(l1->next, NULL, sum / 10);
        } else if (l2) {
            int sum = l2->val + numExtra;
            newNode->val = sum % 10;
            newNode->next = addTwoNumbers_2(NULL, l2->next, sum / 10);
        } else if (numExtra) {
            newNode->val = numExtra;
            newNode->next = NULL;
        } else {
            delete newNode;
            return NULL;
        }
        return newNode;
    }

    // 方法三
    struct ListNode *addTwoNumbers_3(struct ListNode *l1, struct ListNode *l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        } else if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        int sum = l1->val + l2->val;
        struct ListNode *newNode = new ListNode(sum % 10);
        newNode->next = addTwoNumbers_3(l1->next, l2->next);
        if (sum >= 10) {
            struct ListNode *plusOneNode = new ListNode(1);
            newNode->next = addTwoNumbers_3(newNode->next, plusOneNode);
        }
        return newNode;
    }
};

int main() {
    Solution s;
    int arr1[4] = {2, 4, 2, 3};
    int arr2[4] = {5, 6, 7, 9};
    struct ListNode *l1 = arrToList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    struct ListNode *l2 = arrToList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printList(s.addTwoNumbers(l1, l2));
    printList(s.addTwoNumbers_1v2(l1, l2));
    printList(s.addTwoNumbers_1v3(l1, l2));
    printList(s.addTwoNumbers_1v4(l1, l2));
    printList(s.addTwoNumbers_2(l1, l2, 0));
    printList(s.addTwoNumbers_3(l1, l2));

    return 0;
}