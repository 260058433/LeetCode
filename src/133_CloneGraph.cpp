#include "UndirectedGraphNode.cpp"
#include <unordered_map>

using std::unordered_map;

class CloneGraph {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        hash[node] = newNode;
        for (auto p = node->neighbors.begin(); p != node->neighbors.end(); ++p) {
            if (hash.find(*p) == hash.end())
                newNode->neighbors.push_back(cloneGraph(*p));
            else
                newNode->neighbors.push_back(hash[*p]);
        }
        return newNode;
    }

private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
};
