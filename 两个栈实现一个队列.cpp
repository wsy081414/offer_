class queue {
    void push(int value) {
        s1.push(value);
    }
    int pop () {
        if(s2.empty()){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
        return value;
    } 
    stack<int > s1;
    stack<int > s2;
};