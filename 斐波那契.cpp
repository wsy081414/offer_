
//非递归
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int num1 = 0, num2 = 1;
        n -= 1;
        while (n--) {
           int tmp = num1 + num2;
           num1 = num2;
           num2 = tmp;
        }
        return num2;
    }
};

//递归
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return Fibonacci(n-1) + Fibonacci(n-2)
    }
};