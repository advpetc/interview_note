/*
 * list.cpp
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

void prettyPrint(vector<int>& array)
{
    for (int i : array)
        cout << i << " ";
    cout << endl;
    cout << "=======" << endl;
}

int main(int argc, char *argv[]) 
{
    // how to create 2d array
    vector<vector<int>> array{{1, 2, 3}, {4, 5, 6}};
    prettyPrint(array);
    array.erase(array.begin() + 1); // now delete {4,5,6}
    prettyPrint(array);

    // allocate fix size array: all element are initialized as 0
    vector<int> capacityArray(10);
    cout << "size is: " << capacityArray.size() << endl;
    prettyPrint(capacityArray);
    
    // pre-allocate array with value
    vector<int> preAllocated(3, 100); // [100, 100, 100]
    
    // list insert: worst case O(n) -> need to shift all the way down
    int insertArray [] = {1, 2, 3};
    preAllocated.insert(preAllocated.begin(), 
                        insertArray, insertArray + 3);
    prettyPrint(preAllocated);

    // list find: O(last - first)
    if (find(preAllocated.begin(), preAllocated.end(), 20) == preAllocated.end())
        cout << "doesn't exist" << endl;
    else
        cout << "is inside!" << endl;
    
    // list erase: O(n) -> when delete the first element from the list
    vector<int> eraseArray(10, 10);
    prettyPrint(eraseArray);
    eraseArray.erase(eraseArray.begin() + 3);
    prettyPrint(eraseArray);

    // how to delete through element? w/o duplication
    /* first use find the get the iterator, then pass in that iterator to */
    /* erase function to delete */
    
    // list resize: O(n); only update the new element at resized indexes
    vector<int> resizeArray(10);
    prettyPrint(resizeArray);
    resizeArray.resize(5);
    prettyPrint(resizeArray);
    resizeArray.resize(9, 14);
    prettyPrint(resizeArray);

    // TODO: segament tree

    return 0;
}
