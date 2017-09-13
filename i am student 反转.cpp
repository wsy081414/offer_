
//i am student 进行反转

class Solution {
public:
    void Reverseword(string & str, int begin, int end) {
        while(begin < end) {
            std::swap(str[end--], str[begin++]);
        }
    }
    string ReverseSentence(string str) {
        int len = str.length();
        if (len == 0) return "";
        int begin = 0;
        int end = 0;
        Reverseword(str, 0, len - 1);
        int i = 0;
        while ( i < len) {
            while (i < len && str[i] == ' ')
                i++;
            begin = end = i;
            while( i < len && str[i]!= ' ') {
                end++;
                i++;
            }
            Reverseword(str, begin, end - 1);
        }
        return str;
    }
};