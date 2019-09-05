class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone
       directory. */
    PhoneDirectory(int maxNumbers)
    {
        max = maxNumbers;
        for (int i = 0; i < maxNumbers; ++i) {
            available.push(i);
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get()
    {
        if (available.empty())
            return -1;
        int res = available.front();
        available.pop();
        used.insert(res);
        return res;
    }

    /** Check if a number is available or not. */
    bool check(int number)
    {
        if (number >= max || number < 0)
            return false;
        else
            return !used.count(number);
    }

    /** Recycle or release a number. */
    void release(int number)
    {
        if (used.erase(number))
            available.push(number);
    }

private:
    int max;
    queue<int> available;
    unordered_set<int> used;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
