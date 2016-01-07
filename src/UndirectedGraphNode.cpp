#include <vector>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};
