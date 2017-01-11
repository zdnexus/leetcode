//
// Created by Administrator on 2017/1/5 0005.
//
#include<iostream>
#include<string>

using namespace std;

typedef struct item {
    int val;

    item(int x) : val(x) {}
} Item;

int main() {
    char s1[] = "abc";
    char *s2 = "abc";
    int *p1 = NULL;
    int *p2 = new int(0);
    Item *newItem1 = NULL;
    Item *newItem2 = new item(0);

    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(newItem1) << endl;
    cout << sizeof(newItem2) << endl;

    return 0;
}