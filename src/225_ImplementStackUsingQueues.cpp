#include <queue>

using std::queue;

class Stack {
public:
    void push(int x) {
        int n = datas.size();
        datas.push(x);
        for (int i = 0; i < n; ++i) {
            datas.push(datas.front());
            datas.pop();
        }
    }

    void pop() {
        datas.pop();
    }

    int top() {
        return datas.front();
    }

    bool empty() {
        return datas.empty();
    }

private:
    queue<int> datas;
};
