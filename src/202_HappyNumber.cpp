#include <unordered_set>

using std::unordered_set;

class HappyNumber {
public:
    bool isHappy(int n) {
        /*
        unordered_set<int> appear;
        while (n != 1) {
            appear.insert(n);
            n = digitSquareSum(n);
            if (appear.find(n) != appear.end())
                return false;
        }
        return true;
        */

        int fast = n, slow = n;
        while (fast != 1) {
            fast = digitSquareSum(fast);
            if (fast == 1)
                break;
            fast = digitSquareSum(fast);
            slow = digitSquareSum(slow);
            if (fast == slow)
                return false;
        }
        return true;
    }

private:
    int digitSquareSum(int n) {
        int sum = 0;
        while (n) {
            int a = n % 10;
            sum += a * a;
            n /= 10;
        }
        return sum;
    }
};
