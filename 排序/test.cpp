//
// Created by aa on 17/11/28.
//

#include <iostream>

using namespace std;

int main() {
    int arr = 1;
    int *p = &arr;

    cout << *p << endl;
    cout << p[0] << endl;
    cout << arr << endl;

    return 0;
}