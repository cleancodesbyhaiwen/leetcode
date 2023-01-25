class MinStack {
public:
    
    stack<int> stk;
    stack<int> minStk;
    
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(!minStk.empty()){
            int min = minStk.top();
            if(val <= min){
                minStk.push(val);
            }
        }
        else{
            minStk.push(val);
        }
    }
    
    void pop() {
        int popped = stk.top();
        stk.pop();
        int min = minStk.top();
        if(min == popped){
            minStk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
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