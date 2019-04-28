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

// two categories: 
/* 1. comparing sort: bubble, selection, insertion, merge, quick, heap sort */
/* 2. non-comparing sort: counting, bucket sort */ 
struct Product {
    int price, sale;
    bool operator<(Product other) const 
    {
        if (sale == other.sale) 
            return price < other.price;
        else
            return sale < other.sale;

    }
    Product(int price, int sale) 
    {
        this -> price = price;
        this -> sale = sale;
    }
};

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

void prettyPrint(vector<int>& array)
{
    for (int i : array)
        cout << i << " ";
    cout << endl;
    cout << "=======" << endl;
}

void prettyPrint(vector<Product> array)
{
    for (auto& i : array)
        cout << "price is " << i.price << " " << "sale is " << i.sale << endl;
    cout << endl;
    cout << "=======" << endl;
}


void bubbleSortStable(vector<vector<int>> nums)
{
    cout << "stable" << endl;
    for (int i = 0; i < nums.size() - 1; ++i)
        for (int j = nums.size() - 1; j > i; --j)
            if (nums[j][0] < nums[j - 1][0]) // right should always be greater than left
                swap(nums[j][0], nums[j - 1][0]);
    prettyPrint(nums);

    for (int i = 0; i < nums.size() - 1; ++i)
        for (int j = nums.size() - 1; j > i; --j)
            if (nums[j][1] < nums[j - 1][1]) // right should always be greater than left
                swap(nums[j][1], nums[j - 1][1]);
    prettyPrint(nums);
}

void bubbleSortUnstable(vector<vector<int>> nums)
{
    cout << "unstable" << endl;
    for (int i = 0; i < nums.size() - 1; ++i)
        for (int j = nums.size() - 1; j > i; --j)
            if (nums[j - 1][0] >= nums[j][0]) // right should always be greater than left
                swap(nums[j][0], nums[j - 1][0]);
    prettyPrint(nums);
    for (int i = 0; i < nums.size() - 1; ++i)
        for (int j = nums.size() - 1; j > i; --j)
            if (nums[j - 1][1] >= nums[j][1]) // right should always be greater than left
                swap(nums[j][1], nums[j - 1][1]);
    prettyPrint(nums);
}

void selectionSort(vector<int> nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j)
            minIndex = (nums[j] < nums[minIndex]) ? j : i;
        if (minIndex != i)
            swap(nums[i], nums[minIndex]);
    }
    prettyPrint(nums);
}

void insertionSort(vector<int> nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
        for (int j = i + 1; j > 0; --j)
        {
            if (nums[j] < nums[j - 1]) 
                swap(nums[j], nums[j - 1]);
            else break;
        }

    prettyPrint(nums);
}

// time: O(n^2): reversed order
// space: O(1)
void insertionSortBinary(vector<int> nums)
{
    int temp;
    int l, r;
    int mid;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        temp = nums[i + 1];
        l = 0, r = i;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] < temp)
                l = mid + 1;
            else
                r = mid - 1;
        }
        // now l > r, where r is the last value that is smaller or equal to temp
        // now shifting all the value to right by one
        for (int j = i; j > r; --j)
            nums[j + 1] = nums[j];
        nums[r + 1] = temp;
    }
    prettyPrint(nums);
}


void merge(vector<int>& nums, int l, int m, int r)
{
    vector<int> v(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (nums[i] < nums[j]) 
            v[k++] = nums[i++];
        else
            v[k++] = nums[j++];
    }
    while (i <= m)
        v[k++] = nums[i++];

    while (j <= r)
        v[k++] = nums[j++];

    for (int x = 0; x < v.size(); ++x)
        nums[x + l] = v[x];
}

void mergeSort(vector<int>& nums, int l, int r)
{
    int m = (l + r) / 2;
    if (l < r) 
    {
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}

bool cmp(Product l, Product r)
{
    // reverse order by sale and price
    if (l.sale == r.sale)
        return l.price > r.price;
    else
        return l.sale > r.sale;
}

int partition(vector<int>& nums, int left, int right)
{
    // could also be a random number
    int pivotIndex = left;
    int pivot = nums[pivotIndex];
    int l = left + 1, r = right;
    while (l <= r)
    {
        // swap to make sure all then num on the left are smaller than pivot
        // right are greater than pivot
        if (nums[l] > pivot && nums[r] < pivot) 
            swap(nums[l++], nums[r--]);
        if (nums[l] <= pivot) l++;
        if (nums[r] >= pivot) r--;
    }
    swap(nums[pivotIndex], nums[r]);
    return r;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
}

int main(int argc, char *argv[]) 
{
    vector<vector<int>> array{{3, 10}, {1, 9}, {2, 9}, {0, 9}};
    bubbleSortStable(array);
    bubbleSortUnstable(array);

    // using operator overloading
    vector<Product> prod{{3, 10}, {1, 9}, {2, 9}, {0, 9}};
    sort(prod.begin(), prod.end());
    prettyPrint(prod);

    // define a custom comparison function
    sort(prod.begin(), prod.end(), cmp);
    prettyPrint(prod);

    // selection sort
    cout << "selection sort" << endl;
    vector<int> v1{1, 3, 2, 9, 3};
    selectionSort(v1);

    // insertion sort
    cout << "insertion sort" << endl;
    vector<int> v2{1, 3, 2, 9, 3};
    insertionSort(v2);
    cout << "insertion binary sort" << endl;
    insertionSortBinary(v2);

    // merge sort
    vector<int> v3{1, 3, 2, 9, 3};
    mergeSort(v3, 0, v3.size() - 1);
    cout << "merge sort" << endl;
    prettyPrint(v3);

    // quick sort
    vector<int> v4{1, 3, 2, 9, 3};
    quickSort(v4, 0, v4.size() - 1);
    cout << "quick sort" << endl;
    prettyPrint(v4);
    return 0;
}
