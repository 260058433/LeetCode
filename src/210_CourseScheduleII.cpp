#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::pair;
using std::queue;

class CourseScheduleII {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> afterCourse(numCourses);
        vector<int> preCourses(numCourses);
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p) {
            afterCourse[p->second].push_back(p->first);
            ++preCourses[p->first];
        }
        queue<int> candidates;
        for (int i = 0; i < numCourses; ++i)
            if (preCourses[i] == 0)
                candidates.push(i);
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (candidates.empty())
                return vector<int>();
            int cur = candidates.front();
            candidates.pop();
            result.push_back(cur);
            for (auto p = afterCourse[cur].begin(); p != afterCourse[cur].end(); ++p)
                if (--preCourses[*p] == 0)
                    candidates.push(*p);
        }
        return result;
    }
};
