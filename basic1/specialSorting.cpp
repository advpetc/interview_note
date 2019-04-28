/*
 * specialSorting.cpp
 * Copyright (C) 2019 advpetc <chenhaoy@usc.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void prettyPrint(vector<int>& array)
{
    for (int i : array)
        cout << i << " ";
    cout << endl;
    cout << "=======" << endl;
}

void prettyPrint(vector<vector<int>>& array)
{
    for (auto& a : array)
    {
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
    cout << "=======" << endl;
}

void countSort(vector<int> nums)
{
    int global_max = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
        global_max = max(global_max, nums[i]);
    vector<int> count(global_max + 1);
    for (int i = 0; i < nums.size(); ++i)
        count[nums[i]] = count[nums[i]] + 1;
    int index = 0;
    for (int i = 0; i <= global_max; ++i)
        for (int j = 0; j < count[j]; ++j) {
           nums[index++] = i; 
        }
    prettyPrint(nums);
}

// bucket sort: O(n)
void bucketSort(vector<int>& nums) 
{
    int global_max = INT_MIN;
    int global_min = INT_MAX; 
    // find the largest and min value from nums
    for (int n : nums) 
    {
        global_max = max(global_max, n);
        global_min = min(global_min, n);
    }
    int bucketNum = (global_max - global_min) / nums.size() + 1;
    vector<vector<int>> bucket(bucketNum, vector<int>(0));

    // insert into bucket
    for (int n : nums)
    {
        int index = (n - global_min) / nums.size();
        bucket[index].push_back(n);
    }

    // sort each bucket
    for (auto& b : bucket)
        sort(b.begin(), b.end());
    prettyPrint(bucket);
}

int main(int argc, char *argv[]) 
{
    // count sort
    vector<int> v1{1, 4, 2, 3};
    cout << "count sort" << endl;
    countSort(v1);
    vector<int> v2{1, 4, 7, 7, 4, 2, 0};
    cout << "bucket sort" << endl;
    bucketSort(v2);

    return 0;
}
