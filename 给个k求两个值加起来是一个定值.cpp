vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> hash;
    vector<int> result;

    //O(N)的遍历
    for (int i = 0; i < numbers.size(); i++) {
        //首先求出差值
        int numberToFind = target - numbers[i];
        //在hash表当中进行查找
        if (hash.find(numberToFind) != hash.end()) {
            //压入下标
            result.push_back(hash[numberToFind] + 1);
            //压入下标
            result.push_back(i + 1);            
            return result;
        }
        //向hash表当中插入
        hash[numbers[i]] = i;
    }
    return result;
}