class MinStack {
public:
    stack<int>st;
    deque<int>dq;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(dq.empty()){
            dq.push_back(value);
        }else{
            if(value <= dq.front()){
                dq.push_front(value);
            }else{
                dq.push_back(value);
            }
        }
    }
    
    void pop() {
        int temp = st.top();
        st.pop();
        if(temp == dq.front()) dq.pop_front();
        else if(temp == dq.back()) dq.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return dq.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */