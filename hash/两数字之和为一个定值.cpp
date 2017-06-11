
/*给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。

 注意事项

你可以假设只有一组答案。

您在真实的面试中是否遇到过这个题？ 
哪家公司问你的这个题？
感谢您的反馈
样例
给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].
*/


class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int,int> hash;
        vector<int > res;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(hash.find(target-nums[i]) != hash.end())
            {
                res.push_back(hash[target - nums[i]]+1);
                res.push_back(i+1);
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
