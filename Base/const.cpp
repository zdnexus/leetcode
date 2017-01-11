//
// Created by Administrator on 2017/1/11 0011.
//
#include <iostream>

using namespace std;

int main() {
    const int a = 0;
    int const b = 10;

    cout << "const int a = " << a << endl;
    cout << "int const b = " << b << endl;
//    const 不能靠解引用改变它指向的对象的值，以此保护它所指向的常量的常量性：
//    ++a;    //  ERROR
//    ++b;    //  ERROR
    int c = b;
    cout << "int c = b = " << c << endl;
    const int d = c;
    cout << "const int d = c = " << d << endl;
    int const e = d;
    cout << "int const e = d = " << e << endl;

    return 0;
}
