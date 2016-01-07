#include <unordered_map>
#include <utility>

using std::unordered_map;
using std::pair;
using std::make_pair;

struct DoubleList {
    int val;
    DoubleList *pre;
    DoubleList *next;
    DoubleList(int x) : val(x), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        content = new DoubleList(0);
        content->next = content;
        content->pre = content;
    }

    int get(int key) {
        int value = -1;
        auto p = table.find(key);
        if (p != table.end()) {
            p->second.second->pre->next = p->second.second->next;
            p->second.second->next->pre = p->second.second->pre;
            content->next->pre = p->second.second;
            p->second.second->next = content->next;
            content->next = p->second.second;
            p->second.second->pre = content;
            value = p->second.first;
        }
        return value;
    }

    void set(int key, int value) {
        auto p = table.find(key);
        if (p != table.end()) {
            p->second.first = value;
            p->second.second->pre->next = p->second.second->next;
            p->second.second->next->pre = p->second.second->pre;
            content->next->pre = p->second.second;
            p->second.second->next = content->next;
            content->next = p->second.second;
            p->second.second->pre = content;
        } else {
            if (table.size() == _capacity) {
                DoubleList *last = content->pre;
                table.erase(last->val);
                last->pre->next = content;
                content->pre = last->pre;
                delete last;
            }
            DoubleList *p = new DoubleList(key);
            table[key] = make_pair(value, p);
            content->next->pre = p;
            p->next = content->next;
            content->next = p;
            p->pre = content;
        }
    }

private:
    int _capacity;
    DoubleList *content;
    unordered_map<int, pair<int, DoubleList *>> table;
};
