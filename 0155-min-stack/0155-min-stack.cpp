struct var_min{
    int variable;
    int min;
};

class MinStack {
public:
    stack <var_min> min_stack;
    
    MinStack() {}
    
    void push(int val) {
        if(min_stack.size() == 0)
            min_stack.push({val, val});
        else{
            if(min_stack.top().min < val)
                min_stack.push({val, min_stack.top().min});
             else
                 min_stack.push({val, val});
        }
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().variable;
    }
    
    int getMin() {
        return min_stack.top().min;
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