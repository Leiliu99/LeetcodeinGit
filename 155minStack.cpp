class MinStack {
    //using two stacks
private:
    stack<int> normalStack;
    stack<int> minimumStack;
public:
    /** initialize your data structure here. */
//     MinStack() {

//     }

    void push(int x) {
        normalStack.push(x);
        if (minimumStack.empty() || x <= minimumStack.top())  minimumStack.push(x);
    }

    void pop() {
        if(normalStack.top() == minimumStack.top()) minimumStack.pop();
        normalStack.pop();
    }

    int top() {
        return normalStack.top();
    }

    int getMin() {
        return minimumStack.top();
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

class MinStack {
private:
    //By inserting a pair in the stack: first is actual number, second is the minimum number so far
    stack<pair<int, int>> normalStack;
public:
    /** initialize your data structure here. */

    void push(int x) {
        if(normalStack.empty() || x < (normalStack.top()).second){
            pair<int, int> normalPairs = make_pair(x, x);
            normalStack.push(normalPairs);
        }else{
            pair<int, int> normalPairs = make_pair(x, normalStack.top().second);
            normalStack.push(normalPairs);
        }
    }

    void pop() {
        normalStack.pop();
    }

    int top() {
        return (normalStack.top()).first;
    }

    int getMin() {
        return (normalStack.top()).second;
    }
};
