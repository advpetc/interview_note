/*
 * binarySearch.cpp
 * Copyright (C) 2019 advpetc <chenhaoy@usc.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;

/* binary search in recursive way */
int search(vector<int>& nums, int l, int r, int target)
{
    if (r <= l) return -1;
    int m = l + (r - l) / 2;
    if (nums[m] > target)
        return search(nums, l, m, target);
    else if (nums[m] < target)
        return search(nums, m + 1, r, target);
    else return m;
}

/* pow: O(log(n)) */
double pow(double x, int n)
{
    if (n == 0) return 1;
    double y = pow(x, n / 2); // always divide by two -> log(n)
    if (n % 2 == 0) return y * y;
    else return y * y * x;
}

/* 完全平方数: O(sqrt(n)) */
bool isPerfectSquare(int num)
{
    if (num < 0) return false;
    if (num == 1) return true;
    for (int i = 1; i <= num / i; ++i)
        if (i * i == num) return true;
    return false; 
}

int main(int argc, char *argv[]) 
{
    vector<int> nums{1, 2, 3, 4, 5};
    // print the index of 3 in the array
    cout << search(nums, 0, 4, 3) << endl;
    // 10 ^ 3
    cout << pow(10.0, 3) << endl;
    // 97 -> 0: false, 1: true
    cout << isPerfectSquare(97) << endl;
    cout << isPerfectSquare(100) << endl;
    return 0;
}


