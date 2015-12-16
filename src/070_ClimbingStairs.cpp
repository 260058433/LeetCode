class ClimbingStairs {
public:
    int climbStairs(int n) {
        int p = 1, pp = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = p + pp;
            pp = p;
            p = tmp;
        }
        return p;
    }
};
