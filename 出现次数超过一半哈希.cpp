

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
	if( numbers.size() == 0)
  		return 0;
  	unordered_map<int ,int >count;
    int size = numbers.size();
  	for(int i = 0; i < size; ++i) {
  		count[numbers[i]]++;
  		if(count[numbers[i]] > size/2) {
  			return numbers[i];
  		}
  	}
  	return 0;
  }
};

//除了哈希，我们可以使用更加优化的方式
// 更进一步，考虑到这个问题本身的特殊性，我们可以在遍历数组的时候保存两个值：一个candidate，用来保存数组中遍历到的某个数字；一个nTimes，表示当前数字的出现次数，其中，nTimes初始化为1。当我们遍历到数组中下一个数字的时候：

// 如果下一个数字与之前candidate保存的数字相同，则nTimes加1；
// 如果下一个数字与之前candidate保存的数字不同，则nTimes减1；
// 每当出现次数nTimes变为0后，用candidate保存下一个数字，并把nTimes重新设为1。 直到遍历完数组中的所有数字为止。
// 举个例子，假定数组为{0, 1, 2, 1, 1}，按照上述思路执行的步骤如下：

// 1.开始时，candidate保存数字0，nTimes初始化为1；
// 2.然后遍历到数字1，与数字0不同，则nTimes减1变为0；
// 3.因为nTimes变为了0，故candidate保存下一个遍历到的数字2，且nTimes被重新设为1；
// 4.继续遍历到第4个数字1，与之前candidate保存的数字2不同，故nTimes减1变为0；
// 5.因nTimes再次被变为了0，故我们让candidate保存下一个遍历到的数字1，且nTimes被重新设为1。最后返回的就是最后一次把nTimes设为1的数字1。

链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
来源：牛客网

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if (n == 0) return 0;
         
        int num = numbers[0], count = 1;
        for (int i = 1; i < n; i++) {
            if (numbers[i] == num) count++;
            else count--;
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        // Verifying
        count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == num) count++;
        }
        if (count * 2 > n) return num;
        return 0;
    }
};