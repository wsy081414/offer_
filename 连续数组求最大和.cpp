//连续数组求最大和
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.length() == 0)
            return 0;
        int sum = array[0];
        int maxsum  = array[0];
        for (int i = 1; i < array.length(); ++i) {
            sum += arr[i];
            maxsum = std::max(sum, maxsum);
            sum = sum < 0 ? 0 : cur; 
        }
        return maxsum;
    }
};