//
// Created by Administrator on 2017/1/10 0010.
//
#include <iostream>

using namespace std;

//  int *p -> int/const int
void A() {
    //  指向 int 的 p 指针指向 x（int）
    cout << "指向 int 的 p 指针指向 x（int）" << endl;
    int x = 0;
    int *p = &x;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;
    cout << "&x:    " << &x << endl;
    cout << "p:     " << p << endl;
    cout << "&p:    " << &p << endl;



    //  修改 x 的值
    cout << "x（int） = 1" << endl;
    x = 1;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;
    cout << "&x:    " << &x << endl;
    cout << "p:     " << p << endl;
    cout << "&p:    " << &p << endl;



    //  修改 p 指针指向地址的值
    cout << "*p = 2" << endl;
    *p = 2;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;
    cout << "&x:    " << &x << endl;
    cout << "p:     " << p << endl;
    cout << "&p:    " << &p << endl;



    //  再次修改 p 指针指向地址的值
    cout << "*p = *p + 1" << endl;
    *p = *p + 1;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;



    //  改变 p 指针指向的地址，指向 y（int）
    cout << "改变 p 指针指向的地址，指向 y（int）" << endl;
    int y = 10;
    p = &y;
    cout << "y:     " << y << endl;
    cout << "*p:    " << *p << endl;
    cout << "&y:    " << &y << endl;
    cout << "p:     " << p << endl;
    cout << "&p:    " << &p << endl;



    //  指向指针 p 的指针 pp
    cout << "指向指针 p 的指针 pp" << endl;
    int **pp = &p;
    p = &y;
    *pp = &x;
    **pp = 11;
    cout << "x:     " << x << endl;
    cout << "y:     " << y << endl;
    cout << "*p:    " << *p << endl;



    //  改变 p 指针指向地址，指向 int 的 p 指针指向 z（const int）///
//    const int z = 100;
//    p = &z;
}

//  const int *p -> int/const int
void B() {
    //  指向 const int 的指针 p 指向 x（int）
//    cout << "指向 const int 的指针 p 指向 x（int）" << endl;
//    int x = 0;
//    const int *p = &x;
//    cout << "x:     " << x << endl;
//    cout << "*p:    " << *p << endl;



    //  修改 x 的值
//    cout << "x（int） = 1" << endl;
//    x = 1;
//    cout << "x:     " << x << endl;
//    cout << "*p:    " << *p << endl;



    //  修改 p 指针指向地址的值 ///
//    *p = 2;



    // 指向 const int 的指针 p 改变方向指向 y（int）
//    cout << "指向const int的指针 p 改变方向指向 y（int）" << endl;
//    int y = 10;
//    p = &y;
//    cout << "y:     " << y << endl;
//    cout << "*p:    " << *p << endl;



    //  修改 y 的值
//    cout << "y = 11" << endl;
//    y = 11;
//    cout << "x:     " << y << endl;
//    cout << "*p:    " << *p << endl;



    //  修改 p 指针指向地址的值 ///
//    *p = 12;



    // 指向 const int 的指针 p 改变方向指向 z（const int）
//    cout << "指向 const int 的指针 p 改变方向指向 z（const int）" << endl;
//    const int z = 100;
//    p = &z;
//    cout << "z:     " << z << endl;
//    cout << "*p:    " << *p << endl;



    //  修改 p 指针指向地址的值 ///
//    *p = 101;



    //  修改 z 的值 ///
//    z = 102;
}

//  int *const p -> int/const int
void C() {
    //  指向 int 的 const 指针 p 指向 x（int）
    cout << "指向 int 的 const 指针 p 指向 x（int）" << endl;
    int x = 0;
    int *const p = &x;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;



    //  修改 x 的值
    cout << "x = 1" << endl;
    x = 1;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;



    //  修改 p 指针指向地址的值
    cout << "*p = 2" << endl;
    *p = 2;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;



    //  指向 int 的 const 指针 p 改变方向指向 y（int） ///
//    int y = 10;
//    p = &y;



    //  指向 const int 的指针 p 改变方向指向 z（const int ） //???
//    const int z = 100;
//    p = &z;
}

//  const int *const p -> int/const int
void D() {
//  指向 const int 的 const 指针 p 指向 x（int）
    int x = 0;
    const int *const p = &x;
    cout << "指向 const int 的 const 指针 p 指向 x（int）" << endl;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;
    //  修改 x 的值
    cout << "x = 1" << endl;
    x = 1;
    cout << "x:     " << x << endl;
    cout << "*p:    " << *p << endl;
    //  修改 p 指针指向地址的值 //???
//    *p = 2;

    // 指向 const int 的 const 指针 p 指向 y（int） //???
//    int y = 10;
//    p = &y;

    // 指向 const int 的指针 p 改变方向指向 z（const int ） //???
//    const int z = 100;
//    p = &z;
}

int main() {

    A();
//    B();
//    C();
//    D();

    return 0;
}