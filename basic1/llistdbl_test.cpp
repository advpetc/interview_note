#include "llistdbl.h"
#include <iostream>

using namespace std;

int main() {
  LListDbl list;

  // Check if the list is initially empty.
  if (list.empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an item at the head.
  list.insert(0, 3.5);

  // Check if the list is still empty.
  if (!list.empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list.size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list.size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list.get(0) == 3.5) {
    cout << "SUCCESS: 3.5 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3.5 is not at the 0th index of the list, " << list.get(0);
    cout << " is instead." << endl;
  }

  //remove an element at the head
  list.remove(0);
  if (list.empty()) {
        cout << "SUCCESS: List is empty after the remove (one element)." << endl;
  } else {
    cout << "FAIL: List has size " << list.size() << " after one remove." << endl;
  }

  //insert 10 elements into the linkedList
  int count = 10;
  for (int i = 0; i < count; i++) {
    list.insert(i, i + 0.5);
  }
  if (list.size() == 10) {
    cout << "SUCCESS: List has size 10 after ten insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list.size() << " after ten insertion.";
    cout << endl;
  }

  list.insert(20, 1000);
  if (list.size() == 10) {
    cout << "SUCCESS: List can't add element to invaild index." << endl;
  } else {
     cout << "FAIL: List can add element even to invaild index." << endl;
  }

  bool check1 = true;
  for (size_t i = 0; i < 10; i++) {
    if (list.get(i) == i + 0.5) {
      check1 = true;
    } else {
      check1 = false;
      break;
    }
  }
  if (check1) {
    cout << "SUCCESS: the added items are all correct." << endl;
  } else {
    cout << "FAIL: values in each place in the list are not correct." << endl;
  }

  //remove an element at the tail
  list.remove(9);
  if (list.size() == 9) {
      cout << "SUCCESS: List has size of 9 after removing the last elemnt." << endl;
  }else {
    cout << "FAIL: List has size " << list.size() << " after one removal.";
    cout << endl;
  }

  list.remove(10);
  if (list.size() == 9) {
    cout << "SUCCESS: List can't remove out of bound element from the list." << endl;
  } else {
    cout << "FAIL: List can get remove even from invaild index." << endl;
    cout << "size is: " << list.size() << "*********" << endl;
  }

  bool check2 = true;
  for (size_t i = 0; i < 9; i++) {
    if (list.get(i) == i + 0.5) {
      check2 = true;
    } else {
      check2 = false;
      break;
    }
  }
  if (check2) {
    cout << "SUCCESS: the added items are all correct after the removal of the tail element." << endl;
  } else {
    cout << "FAIL: values in each place in the list are not correct." << endl;
  }

  //remove the middle item from the linkedlist
  list.remove(5);
  if (list.size() == 8) {
    cout << "SUCCESS: List has size of 8 after removing the middle element." << endl;
  } else {
    cout << "FAIL: List has size " << list.size() << " after one removal.";
    cout << endl;
  }
  bool check3 = true;
  for (size_t i = 0; i < 4; i++) {
    if (list.get(i) == i + 0.5) {
      check3 = true;
    } else {
      check3 = false;
      break;
    }
  }
  if (check3) {
    cout << "SUCCESS: the first 5 element are all correct after the removal of the 5th element." << endl;
  } else {
    cout << "FAIL: values in each place in the list are not correct." << endl;
  }

  bool check4 = true;
  for (size_t i = 5; i < 8; i++) {
    if (list.get(i) == i + 1.5) {
      check4 = true;
    } else {
      check4 = false;
      break;
    }
  }
  if (check4) {
    cout << "SUCCESS: the last 5 element are all correct after the removal of the 5th element." << endl;
  } else {
    cout << "FAIL: values in each place in the list are not correct." << endl;
  }
  return 0;
}
