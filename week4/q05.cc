class MinStack {
    vector<int> stack;
    vector<int> min_vals;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.size() == 0) {
            min_vals.push_back(val);
        } else {
            min_vals.push_back(min(val, min_vals.back()));
        }

        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back(); 
        min_vals.pop_back(); 
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_vals.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
