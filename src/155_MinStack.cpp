#include <stack>

using std::stack;

class MinStack {
public:
    void push(int x) {
        if (x <= min || data.empty()) {
            data.push(min);
            min = x;
        }
        data.push(x);
    }

    void pop() {
        if (data.top() == min) {
            data.pop();
            min = data.top();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min;
    }

private:
    stack<int> data;
    int min;
};
