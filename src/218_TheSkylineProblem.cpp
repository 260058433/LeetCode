#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::pair;
using std::make_pair;
using std::priority_queue;

class Comp {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.second < b.second)
            return true;
        else if (b.second < a.second)
            return false;
        else
            return a.first < b.first;
    }
};

class TheSkylineProblem {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        /*
        vector<pair<int, int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> ends;
        int preX = 0, preHeight = 0;
        for (int i = 0; i < buildings.size(); ++i) {
            int curX = buildings[i][0];
            while (!ends.empty() && ends.top().first < curX) {
                int x = ends.top().first;
                while (!ends.empty() && ends.top().first <= x)
                    ends.pop();
                int h = ends.empty() ? 0 : ends.top().second;
                result.push_back(make_pair(x, h));
                preHeight = h;
            }
            int curHeight = buildings[i][2];
            if (curHeight > preHeight) {
                if (!result.empty() && result.back().first == curX)
                    result.back().second = curHeight;
                else
                    result.push_back(make_pair(curX, curHeight));
                preHeight = curHeight;
            }
            ends.push(make_pair(buildings[i][1], curHeight));
        }
        while (!ends.empty()) {
            int x = ends.top().first;
            while (!ends.empty() && ends.top().first <= x)
                ends.pop();
            int h = ends.empty() ? 0 : ends.top().second;
            result.push_back(make_pair(x, h));
        }
        return result;
        */

        vector<pair<int, int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> waitingBuildings;
        int cur = 0, len = buildings.size();
        while (cur < len || !waitingBuildings.empty()) {
            int curX = waitingBuildings.empty() ? buildings[cur][0] : waitingBuildings.top().first;
            if (cur >= len || buildings[cur][0] > curX) {
                while (!waitingBuildings.empty() && waitingBuildings.top().first <= curX)
                    waitingBuildings.pop();
            } else {
                curX = buildings[cur][0];
                while (cur < len && buildings[cur][0] == curX) {
                    waitingBuildings.push(make_pair(buildings[cur][1], buildings[cur][2]));
                    ++cur;
                }
            }
            int curH = waitingBuildings.empty() ? 0 : waitingBuildings.top().second;
            if (result.empty() || result.back().second != curH)
                result.push_back(make_pair(curX, curH));
        }
        return result;
    }
};
