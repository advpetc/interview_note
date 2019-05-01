class MinStack {

private:
    /* Method 1: use two stack */
    /* stack<int> s1; */
    /* stack<int> s2; */
    
    /* Method 2: use an int to track the min */
    stack<int> s;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX; 
    }
    
    void push(int x) {
        /* s1.push(x); */
        /* if (s2.empty() || x <= getMin()) s2.push(x); */
        
        // only push the old minimum value when the current 
        // minimum value changes after pushing the new value x
        if (x <= min)
        {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        /* if (s1.top() == getMin()) s2.pop(); */
        /* s1.pop(); */
        
        // if pop operation could result in the changing of the current minimum value, 
        // pop twice and change the current minimum value to the last minimum value.
        int curr_top = s.top();
        s.pop();
        if (curr_top == min)
        {
            min = s.top();
            s.pop();
        }
    }
    
    int top() {
        /* return s1.top(); */
        return s.top();
    }
    
    int getMin() {
        /* return s2.top(); */
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
