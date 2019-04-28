#include "llistdbl.h"
#include <cstdlib>
#include <iostream>
using namespace std;
LListDbl::LListDbl()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

LListDbl::~LListDbl()
{
    clear();
}

bool LListDbl::empty() const
{
    return size_ == 0;
}

int LListDbl::size() const
{
    return size_;
}

/**
 * Complete the following function
 * insert back
 */
void LListDbl::insert(int loc, const double& val)
{
    if (loc < 0 || loc > size_) return;
    Item* temp = new Item;
    temp -> val = val;
    if (size_ == 0) {
        if (loc == 0) { //add to the empty list
            temp -> next = NULL;
            temp -> prev = NULL;
            head_ = temp;
            tail_ = temp;
        } else return;
    } else if (loc == size_) { // add to the tail of non empty list
        tail_ -> next = temp;
        temp -> prev = tail_;
        temp -> next = NULL;
        tail_ = temp;
    } else if (loc < size_ && loc > 0) {// add to the middle
        Item* curr = this -> getNodeAt(loc - 1);
        Item* myNext = curr -> next;
        temp -> prev = curr;
        temp -> next = myNext;
        curr -> next = temp;
        myNext -> prev = temp;
    } else if(loc == 0){ // add to the head
        head_ -> prev = temp;
        temp -> next = head_;
        temp -> prev = NULL;
        head_ = temp;
    }
    size_++;
}

/**
 * remove element from index
 */
void LListDbl::remove(int loc)
{
    if (loc < 0 || loc >= size_ || size_ == 0) return;
    if (size_ == 1) {//only one element
        if (loc == 0) {
            delete head_;
            head_ = NULL;
            tail_ = NULL;
            size_ = 0;
            return;
        } else return;
    } else if (size_ > 0) {
        if (loc == size_ - 1) {//at the tail
            Item* last = tail_ -> prev;
            delete last -> next;
            last -> next = NULL;
            tail_ = last;
        } else if (loc == 0) {//at the head
            Item* first = head_ -> next;
            delete first -> prev;
            first -> prev = NULL;
            head_ = first;
        } else if (loc < size_ && loc > 0) {
            Item* toBeRemove = this -> getNodeAt(loc);
            Item* myNext = toBeRemove -> next;
            Item* myPre = toBeRemove -> prev;
            myPre -> next = myNext;
            myNext -> prev = myPre;
            delete toBeRemove;
        } else return;
    }
    size_--;
}

void LListDbl::set(int loc, const double& val)
{
    Item *temp = getNodeAt(loc);
    temp->val = val;
}

double& LListDbl::get(int loc)
{
    Item *temp = getNodeAt(loc);
    return temp->val;
}

double const & LListDbl::get(int loc) const
{
    Item *temp = getNodeAt(loc);
    return temp->val;
}

void LListDbl::clear()
{
    while(head_ != NULL){
        Item *temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
{
    Item *temp = head_;
    if(loc >= 0 && loc < size_){
        while(temp != NULL && loc > 0){
            temp = temp->next;
            loc--;
        }
        return temp;
    }
    else {
        //throw std::invalid_argument("bad location");
        return NULL;
    }
}
