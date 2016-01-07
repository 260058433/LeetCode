#include <vector>

using std::vector;

class Candy {
public:
    int candy(vector<int> &ratings) {
        int result = 0;
        int i = 0, n = ratings.size();
        while (i < n - 1) {
            int up = 1;
            while (i < n - 1 && ratings[i] < ratings[i + 1]) {
                ++i;
                result += up++;
            }
            if (i < n - 1 && ratings[i] == ratings[i + 1]) {
                result += up;
                up = 0;
                ++i;
                while (i < n - 1 && ratings[i] == ratings[i + 1]) {
                    ++i;
                    ++result;
                }
            }
            int down = 1;
            while (i < n - 1 && ratings[i] > ratings[i + 1]) {
                ++i;
                result += down++;
            }
            result += up < down ? down : up;
            --result;
        }
        return ++result;
    }
};
