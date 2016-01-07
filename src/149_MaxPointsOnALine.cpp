#include <vector>
#include <unordered_map>
#include <utility>
#include <functional>
#include <cstddef>

using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::hash;
using std::size_t;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class HashFunc {
public:
    size_t operator()(const pair<int, int> &p) const {
        hash<int> func;
        return func(p.first) ^ func(p.second);
    }
};

class MaxPointsOnALine {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        int n = points.size();
        unordered_map<pair<int, int>, int, HashFunc> lines;
        for (int i = 0; i < n; ++i) {
            int curMax = 0;
            int same = 1;
            for (int j = i + 1; j < n; ++j) {
                int x = points[i].x - points[j].x, y = points[i].y - points[j].y;
                if (x == 0 && y == 0) {
                    ++same;
                    continue;
                }
                pair<int, int> slope;
                int g = gcd(x, y);
                slope.first = y / g;
                slope.second = x / g;
                if (curMax < ++lines[slope])
                    curMax = lines[slope];
            }
            curMax += same;
            if (result < curMax)
                result = curMax;
            lines.clear();
        }
        return result;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }
};
