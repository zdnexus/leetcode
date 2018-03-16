//
// Created by zdnexus on 17/11/30.
//

#include <iostream>

using namespace std;

int main() {
    unsigned int arr[10];
    unsigned int sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    cout << sum << endl;
    cout << arr[10] << endl;

    return 0;
}