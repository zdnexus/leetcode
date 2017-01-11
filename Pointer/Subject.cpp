//
// Created by Administrator on 2017/1/11 0011.
//

#include <iostream>

using namespace std;

//  1
class Swap_Solution {
public:
    void swap1(int p, int q) {
        int temp;
        temp = p;
        p = q;
        q = temp;
    }

    void swap2(int *p, int *q) {
        int *temp;
        *temp = *p;
        *p = *q;
        *q = *temp;
    }

    void swap3(int *p, int *q) {
        int *temp;
        temp = p;
        p = q;
        q = temp;
    }

    void swap4(int *p, int *q) {
        int temp;
        temp = *p;
        *p = *q;
        *q = temp;
    }

    void swap5(int &p, int &q) {
        int temp;
        temp = p;
        p = q;
        q = temp;
    }
};

void A() {
    Swap_Solution s;
    int a = 1, b = 2;
//    s.swap1(a,b);
//    s.swap2(&a, &b);
//    s.swap3(&a,&b);
//    s.swap4(&a,&b);
//    s.swap5(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


//  2
char *strReturn() {
    char str[] = "hello world";
    return str;
}

void B() {
    char *p = strReturn();
    cout << p << endl;
}


int main() {
    A();
    B();

    return 0;
}