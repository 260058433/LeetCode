class ReverseInteger {
public:
    int reverse(int x) {
        bool negtive = x < 0;
        x = x >= 0 ? x : -x;
        int result = 0;
        while (x) {
            int tmp = result * 10 + x % 10;
            if ((tmp - x % 10) / 10 != result)
                return 0;
            result = tmp;
            x /= 10;
        }
        if (negtive)
            result = -result;
        return result;
    }
};
