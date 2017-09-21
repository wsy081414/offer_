
//关于快速幂求pow


class Solution {
public:
    double Power(double base, int exponent) {
        long long tmp = abs(exponent);
        double s = 1.0;
        while(tmp) {
            if (tmp & 1) s *= base;
            base *= base;
            tmp >>= 1;
        }

        return exponent > 0 ? s : 1/s;
    }
};