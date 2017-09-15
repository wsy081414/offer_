//三步反转字符串
//

class Solution {
public:
    
    void Reverseword(string &str, int begin, int end) {
        while (begin < end) {
            std::swap(str[beign++], str[end--]);
        }
    }
    string LeftRotateString(string str, int n) {
        int len = std.length();
        if ( str != "" && n <= len ) {
            if(n >= 0 && n <= len) {
                int begin1 = 0;
                int begin2 = n;
                int end1 = n-1;
                int end2 = len - 1;
                Reverseword(str, begin1, end1);
                Reverseword(str, begin2, end2);
                Reverseword(str, 0, len-1);
            }
        }
        return str;
    }
};