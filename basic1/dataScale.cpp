/*
 * dataScale.cpp
 * Copyright (C) 2019 advpetc <advpetc@core>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;
/*
 * n < 10^8
 * 1. > O(n): 2^n (combination), n! (permutation), n^3 (DP/others), nlogn (heap/divide)
 * 2. < O(n): sqrt(n) (prime/square), logn (binary search)
 */
int main() {
    for (int i = 0; i < 9; i++) {
        double num = pow((double) i, 10.0); // num = 10 100 1000
        int sum = 0;
        clock_t before = clock();
        for (int j = 0; j <= num; ++j)
            sum += j;
        clock_t after = clock();
        double per = double(after - before) / CLOCKS_PER_SEC;
        cout << "10^" <<  i << ": " << per;
    }
}

