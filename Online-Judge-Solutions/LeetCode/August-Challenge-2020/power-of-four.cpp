class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0) return false;
        int cntOne = 0, posOne = 0, in = 0;
        while (num > 0) {
            if (num % 2) {
                ++cntOne;
                posOne = in;
            }
            num /= 2;
            ++in;
        }
        if (cntOne == 1 && posOne % 2 == 0) return true;
        return false;
    }
};