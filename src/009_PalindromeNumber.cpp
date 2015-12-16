class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        /*
        if (x < 0)
            return false;
        int digit = 1;
        while (x / digit / 10) {
            digit *= 10;
        }
        while (x) {
            int a = x / digit, b = x % 10;
            if (a != b)
                return false;
            x = x % digit / 10;
            digit /= 100;
        }
        return true;
        */

        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int low = 0;
        while (x > low) {
            low = low * 10 + x % 10;
            x /= 10;
        }
        return x == low || x == low / 10;
    }
};
