/*
 * q9.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculatorTax(int income) {
    if (income < 100000) return 0.95 * income;
    else if (income < 1000000) return 0.9 * income;
    else return 0.8 * income;
}

int main(int argc, char *argv[]) 
{
    cout << calculatorTax(200000) << endl;
    cout << calculatorTax(100000) << endl;
    cout << calculatorTax(20000000) << endl;
    return 0;
}

