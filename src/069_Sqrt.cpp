class Sqrt {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int i = 0;
        int result = 0;
        while ((long)(1 << i) * (long)(1 << i) <= x)
            ++i;
        while (i > 0) {
            --i;
            long tmp = (long)(result | 1 << i) * (long)(result | 1 << i);
            if (tmp <= x) {
                result |= 1 << i;
                if (tmp == x)
                    break;
            }
        }
        return result;
    }
};
