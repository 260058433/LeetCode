#include "ListNode.cpp"
#include <vector>

using std::vector;

class MergeKSortedLists {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        init(lists);
        ListNode preHead(0);
        ListNode *p = &preHead;
        while (p) {
            p->next = next(lists);
            p = p->next;
        }
        return preHead.next;
    }

private:
    vector<int> loserTree;

    void init(vector<ListNode *> &lists) {
        loserTree = vector<int>(lists.size(), -1);
        for (int i = 0; i < lists.size(); ++i) {
            int j = (lists.size() + i) / 2;
            int t = i;
            while (j) {
                if (loserTree[j] == -1) {
                    loserTree[j] = t;
                    break;
                } else if (lists[t] == nullptr || (lists[loserTree[j]] != nullptr && lists[loserTree[j]]->val < lists[t]->val)) {
                    int tmp = t;
                    t = loserTree[j];
                    loserTree[j] = tmp;
                }
                j /= 2;
            }
            loserTree[0] = t;
        }
    }

    ListNode *next(vector<ListNode *> &lists) {
        int i = loserTree[0];
        ListNode *result = lists[i];
        if (lists[i] != nullptr)
            lists[i] = lists[i]->next;
        int j = (lists.size() + i) / 2;
        while (j) {
            if (lists[i] == nullptr || (lists[loserTree[j]] != nullptr && lists[loserTree[j]]->val < lists[i]->val)) {
                int tmp = i;
                i = loserTree[j];
                loserTree[j] = tmp;
            }
            j /= 2;
        }
        loserTree[0] = i;
        return result;
    }
};
