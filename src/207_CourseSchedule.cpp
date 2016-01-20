#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::pair;
using std::queue;

class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        /*
        vector<int> preNum(numCourses);
        vector<vector<int>> afterCourses(numCourses);
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p) {
            ++preNum[p->first];
            afterCourses[p->second].push_back(p->first);
        }
        queue<int> candidates;
        for (int i = 0; i < numCourses; ++i)
            if (preNum[i] == 0)
                candidates.push(i);
        while (!candidates.empty()) {
            int course = candidates.front();
            candidates.pop();
            --numCourses;
            for (auto p = afterCourses[course].begin(); p != afterCourses[course].end(); ++p) {
                if (--preNum[*p] == 0)
                    candidates.push(*p);
            }
        }
        return numCourses == 0;
        */

        vector<vector<int>> graph(numCourses);
        for (auto p = prerequisites.begin(); p != prerequisites.end(); ++p)
            graph[p->second].push_back(p->first);
        vector<char> color(numCourses, 'W');
        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 'W' && dfsCycle(graph, color, i))
                return false;
        }
        return true;
    }

private:
    bool dfsCycle(vector<vector<int>> &graph, vector<char> &color, int course) {
        color[course] = 'G';
        for (auto p = graph[course].begin(); p != graph[course].end(); ++p) {
            if (color[*p] == 'G' || color[*p] == 'W' && dfsCycle(graph, color, *p))
                return true;
        }
        color[course] = 'B';
        return false;
    }
};
