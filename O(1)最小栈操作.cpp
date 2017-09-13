class Solution {
public:
    void push(int value) {
      s1.push(value);
      if(s2.empty()) {
        s2.push(value);
      }
      else if (value <= s2.top()) {
        s2.push(value);
      }
      else {
        s2.push(s2.top());
      }
    }
    void pop() {
      s1.pop();
      s2.pop();
    }
    int top() {
      return s1.top();
    }
    int min() {
      return s2.top();
    }
protected:
  std::stack<int > s1;
  std::stack<int > s2;
};