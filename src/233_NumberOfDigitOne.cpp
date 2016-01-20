class NumberOfDigitOne {
public:
    int countDigitOne(int n) {
        /*
        if (n <= 0)
            return 0;
        int result = 0;
        long i = 1;
        while (n / i) {
            result += n / i / 10 * i;
            if (n / i % 10 == 1)
                result += n % i + 1;
            else if (n / i % 10 > 1)
                result += i;
            i *= 10;
        }
        return result;
        */

        int result = 0;
        for (long long i = 1; i <= n; i *= 10)
            result += (n / i + 8) / 10 * i + (n / i % 10 == 1) * (n % i + 1);
        return result;
    }
};
