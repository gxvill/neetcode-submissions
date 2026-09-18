class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        bool carry = 0;

        for(int i = 0; i < 32; i++){
            int sum;
            bool ba = a & 1;
            bool bb = b & 1;
            
            sum = carry + ba + bb;

            carry = sum / 2;
            res |= ((sum % 2) << i);

            a >>= 1;
            b >>= 1;
        }
        return res;
    }
};
