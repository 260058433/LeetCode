#include <stack>

using std::stack;

class ImplementQueueUsingStacks {
public:
    void push(int x) {
        in.push(x);
    }

    void pop(void) {
        adjust();
        out.pop();
    }

    int peek(void) {
        adjust();
        return out.top();
    }

    bool empty(void) {
        return in.empty() && out.empty();
    }

private:
    stack<int> in;
    stack<int> out;

    void adjust() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
};
