//
// Created by Administrator on 2017/1/11 0011.
//

#include <iostream>

using namespace std;

int main() {
    char *s1 = "hello";
    //  s1 是指向一块内存区域，它指向的内存区域的大小可以随时改变，
    cout << *s1 << endl;
    cout << s1 << endl;
    s1 = "world";
    cout << *s1 << endl;
    cout << s1 << endl;
    //  而且当指针指向常量字符串时，它的内容是不可以被修改的，否则在运行时会报错。
    *(++s1) = 3;

    return 0;
}