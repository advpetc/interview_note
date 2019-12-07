/*
 * sorting.cpp
 * Copyright (C) 2019 advpetc <chenhaoy@usc.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

// bucket sort: O(n)
void bucketSort(vector<int>& nums, int k) 
{
	if (k > nums.size())
		return;
    int global_max = INT_MIN;
    int global_min = INT_MAX;
    // find the largest and min value from nums
    for (int n : nums) 
    {
        global_max = max(global_max, n);
        global_min = min(global_min, n);
    }
    int bucketNum = k;
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
    vector<int> v1{1, 4, 7, 7, 4, 2, 0};
    cout << "bucket sort" << endl;
    bucketSort(v1, 2);

    vector<int> v2{1, 5, 3, 2, 4}; // 0, 4
    bucketSort(v2, 5); // 12345


    return 0;
}
