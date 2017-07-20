class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
      if ((pushV.size() != popV.size()) | (pushV.size() <= 0) | (pushV.size() <= 0)) {
        return false;
      }
      stack<int > s;
      int j = 0;
      for (int i = 0; i < pushV.size(); ) {
        s.push(pushV[i++]);
        while ( (j < popV.size() )&& (s.top() == popV[j])) {
          s.pop();
          j++;
        }
      }
      return s.empty();
    }
};