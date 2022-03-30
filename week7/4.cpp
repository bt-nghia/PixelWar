#include <iostream>

int* getPointerToArray(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    return arr;
}