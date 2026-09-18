class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;

        for(int i = 0; i < 32; i++){
            int sum = 0;
            int ba = a & 1;
            int bb = b & 1;
            
            sum = carry + ba + bb;

            switch(sum){
            case 1:{
                res |= (1 << i);
                carry = 0;
                break;
            }
            case 2:{
                carry = 1;
                break;
            }
            case 3:{
                res |= (1 << i);
                carry = 1;
                break;
            }
            }
            a >>= 1;
            b >>= 1;
        }
        return res;
    }
};
