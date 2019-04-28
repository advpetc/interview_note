/*
 * recursion.cpp
 * Copyright (C) 2019 advpetc <advpetc@core>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * fib(n) = fib(n-1) + fib(n-2)
 * fib(1) = fib(2) = 1
 * 
 * but it's not efficient: 
 *  fib(3) = fib(2) + fib(1)
 *  fib(4) = fib(3) + fib(2) = fib(2) + fib(1) + fib(2) which visits  fib(2) + fib(1)
 * again, so cache them!
 *
 * same to LC70
 */
int fib1(int n)
{
    if (n == 1 || n == 2) return 1;
    else return fib1(n - 1) + fib1(n - 2);
}

/*
 * w/ memorizations: top down
 */
vector<int> memo(31);
int fib2(int n)
{
    if (n <= 1) return n;
    else if (memo[n] != 0) return memo[n];
    else return memo[n] = fib2(n - 1) + fib2(n - 2);
}

/*
 * w/ memorizations: bottom up
 */

int fib3(int n)
{
    if (n <= 1) return n;
    vector<int> cache(n + 1);
    cache[1] = 1;
    for (unsigned i = 2; i <= n; ++i)
        cache[i] = cache[i - 1] + cache[i - 2];
    return cache[n];
}


/*
 * LC 118
 */
vector<vector<int>> generate(int numRows)
{
    /* : naive w/o optimize */
    /* vector<vector<int>> triangle; */
    /* if (numRows == 0) return triangle; */
    /* if (numRows == 1) */
    /* { */
    /*     vector<int> first{1}; */
    /*     triangle.push_back(first); */
    /* } */
    /* vector<int> currRow; */
    /* currRow.push_back(1); */
    /* vector<vector<int>> temp = generate(numRows - 1); */
    /* vector<int> prevRow = temp.back(); */
    /* for (unsigned i = 0; i < prevRow.size() - 1; ++i) */
    /*     currRow.push_back(prevRow[i] + prevRow[i + 1]); */
    /* currRow.push_back(1); */
    /* temp.push_back(currRow); */
    /* return temp; */

    /* : w/ optimization */
    vector<vector<int>> r(numRows);
    for (unsigned i = 0; i < numRows; ++i)
    {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;
        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }
    return r;
}

int main() 
{
    cout << fib1(10) << endl;
    cout << fib2(10) << endl;
    cout << fib3(10) << endl;
    vector<vector<int>> ret = generate(20);
    for (auto& v : ret)
    {
        cout << "row";
        for (int i : v)
            cout << i << " " << endl;
    }
}

