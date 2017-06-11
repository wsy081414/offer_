


/*丢失的第一个正整数 

难度系数 中等 通过率 22%
 描述
 笔记
 数据
 评测
给出一个无序的正数数组，找出其中没有出现的最小正整数。

您在真实的面试中是否遇到过这个题？ Yes
样例
如果给出 [1,2,0], return 3
如果给出 [3,4,-1,1], return 2

挑战 
只允许时间复杂度O(n)的算法，并且只能使用常数级别的空间。
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> nums) {
        // write your code here
        for(int i = 0 ;i<nums.size(); i++)
        {
            while(nums[i] != nums.size()+1 && nums[i]>=1 && nums[i] < nums.size())
            {
                if(nums[nums[i] - 1] == nums[i])
                    break;
                else
                    swap(nums[i],nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {  
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};