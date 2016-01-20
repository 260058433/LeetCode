#include <vector>

using std::vector;

class PerfectSquares {
public:
    int numSquares(int n) {
        /*
        vector<int> squares(n + 1);
        for (int i = 1; i <= n; ++i) {
            squares[i] = i;
            for (int j = 1; j * j <= i; ++j) {
                if (squares[i - j * j] + 1 < squares[i])
                    squares[i] = squares[i - j * j] + 1;
            }
        }
        return squares[n];
        */

        //Since squares is a static vector, if squares.size() > n, we have already calculated the result during previous function calls and we can just return the result now.
        static vector<int> squares(1);
        while (squares.size() <= n) {
            int i = squares.size(), cur = squares.size();
            for (int j = 1; j * j <= i; ++j)
                if (squares[i - j * j] + 1 < cur)
                    cur = squares[i - j * j] + 1;
            squares.push_back(cur);
        }
        return squares[n];
    }
};
