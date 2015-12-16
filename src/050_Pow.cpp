class Pow {
public:
    double myPow(double x, int n) {
        double result = 1;
        long e = n;
        e = e < 0 ? -e : e;
        while (e) {
            if (e & 1) {
                result *= x;
            }
            x = x * x;
            e >>= 1;
        }
        if (n < 0)
            result = 1 / result;
        return result;
    }
};
