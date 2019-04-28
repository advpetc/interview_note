/*
 * complexity.cpp
 * Copyright (C) 2019 advpetc <advpetc@core>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
using namespace std;

// space: O(1); time: O(n)
int sum(vector<int> &nums) 
{
    int res = 0;
    for (unsigned i = 0; i < nums.size(); ++i)
        res += nums[i];
    return res;
}

// space: O(n); time: O(n)
vector<int> copy(vector<int> &nums)
{
    vector<int> ret;
    for (int num : nums)
        ret.push_back(num);
    return ret;
}

// space: O(m*n); time: O(m*n)
vector<vector<int>> copy2(vector<vector<int>> nums) {
    vector<vector<int>> res(nums[0].size());
    for (unsigned i = 0; i < nums.size(); ++i) {
        for (unsigned j = 0; j < nums[0].size(); ++j)
            res[i][j] = nums[i][j];
    }
    return res;
}

int main() {
    vector<int> v{1, 2, 3};
    cout << sum(v) << endl;
    vector<int> copy_num = copy(v);
    for (int c : copy_num)
        cout << c << endl;

    return 0;
}

/* data is too large? how to save/compute?
 * 1. System Design: MapReduce (multiple computer) / big data (distributed
 * computing.
 * 2. bit manipulation
 */

