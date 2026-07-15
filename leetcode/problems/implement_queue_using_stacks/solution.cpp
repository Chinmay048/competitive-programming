class MyQueue {
    stack<int> inStack;
    stack<int> outStack;
    void transferIfEmpty() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
public:
    MyQueue() {}
    void push(int x) {
        inStack.push(x);
    }
    int pop() {
        transferIfEmpty();
        int topVal = outStack.top();
        outStack.pop();
        return topVal;   
    }
    
    int peek() {
        transferIfEmpty();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */