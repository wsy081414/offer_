//数组当中重复的数

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int,int> mp;
        for (int i = 0; i < length; ++i) {
            mp[numbers[i]]++;
        }
        for (int i = 0; i < length; ++i) {
            if (mp[numbers[i]] > 1) {
                *duplication = numbers[i];
                break;
            }
        }
        return res;
    }
};