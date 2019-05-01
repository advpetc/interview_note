/*
 * stack.cpp
 * Copyright (C) 2019 advpetc <chenhaoy@usc.edu>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int level = 1;

void error()
{
    level++;
    error();
}

int f1(int n)
{
    if (n == 1)
        return 1;
    else
        return f1(n - 1);
}

int f2(int n)
{
    if (n == 1)
        return 1;
    else
        return 1 + f2(n - 1);
}
int sum = 0;
// stack iterations
void sum1(int num)
{
    if (num == 0) return;
    sum += num; 
    sum1(num - 1);
}

int sum2(int num)
{
    if (num == 0) return 0;
    sum += num; 
    return num + sum2(num - 1);
}

int iteration(int num) {
    int sum = 0, n = 1;
    while (n <= num)
        sum += n++;
    return sum;
}

int main(int argc, char *argv[]) 
{
    /* error(); */
    sum1(10);
    printf("sum from 0 - 10 is (sum1): %d\n", sum);
    sum = 0;
    sum2(10);
    printf("sum from 0 - 10 is (sum2): %d\n", sum);
    printf("sum from 0 - 10 is (iteration): %d\n", iteration(10));
    return 0;
}

