

/*给定一个字符串source和一个目标字符串target，在字符串source中找到包括所有目标字符串字母的子串。

 注意事项

如果在source中没有这样的子串，返回""，如果有多个这样的子串，返回起始位置最小的子串。

您在真实的面试中是否遇到过这个题？ 
哪家公司问你的这个题？
感谢您的反馈
说明
在答案的子串中的字母在目标字符串中是否需要具有相同的顺序？

——不需要。

样例
给出source = "ADOBECODEBANC"，target = "ABC" 满足要求的解  "BANC"

挑战 
要求时间复杂度为O(n)

*/


class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &s, string &t) {
        // write your code here
        unordered_map<char, int> mp;
        for (char now : t) {
            mp[now]++;
        }
        int count = mp.size();
        int j = 0;
        int ans = INT_MAX;
        string res; 
        for (int i = 0; i < s.size(); i++) {
            while(count != 0 && j < s.size()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    count--;
                }
                j++;
                if (count == 0) {
                    break;
                }
            }
            if (count == 0 && j - i< ans) {
                ans = j - i;
                res = s.substr(i, j - i);
                
            }
            if(mp[s[i]] == 0) {
                count++;
            }
            mp[s[i]]++;
        }
        return res;
    }


};
