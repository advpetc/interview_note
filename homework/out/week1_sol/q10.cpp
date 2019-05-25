/*
 * q10.cpp
 * Copyright (C) 2019 advpetc <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LIMIT 2
#define sub_time(i) (i % 2 == 0)
int main(int argc, char *argv[]) 
{
    vector<string> ret(12 * LIMIT);
    for (size_t i = 0; i < LIMIT; ++i) {
        string sub = sub_time(i) ? "AM" : "PM";
        size_t offset = i * 12;
        for (size_t j = 0; j < 12; ++j) {
            ret[j + offset] = to_string(sub_time(i) ? j : 12 - j) + sub;
        } 
    }
    for (auto r : ret) { cout << r << " "; }
    return 0;
}

