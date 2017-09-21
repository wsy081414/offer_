
//调整奇偶

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for (int i = 0; i < array.size(); ++i) {
            for ( int j = array.size() - 1; j >= 0; --j) {
                if(array[j] % 2 ==0 && array[j+1] % 2 == 1) {
                    std::swap(array[j], array[j + 1]);
                }
            }
        }
    }
};


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> a;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] % 2 == 0) a.push_back(array[i]);
        }
        
    }
};