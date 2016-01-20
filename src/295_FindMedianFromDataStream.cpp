#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::greater;
using std::less;
using std::swap;

template <typename Comp>
class Heap {
public:
    int top() const {
        return data.front();
    }

    void push(int num) {
        data.push_back(num);
        int child = data.size() - 1;
        while (child > 0) {
            int parent = (child - 1) / 2;
            if (f(data[parent], num))
                data[child] = data[parent];
            else
                break;
            child = parent;
        }
        data[child] = num;
    }

    void pop() {
        data[0] = data.back();
        data.pop_back();
        int parent = 0;
        while (parent < data.size() / 2) {
            int child = parent * 2 + 1;
            if (child + 1 < data.size() && f(data[child], data[child + 1]))
                ++child;
            if (f(data[parent], data[child]))
                swap(data[parent], data[child]);
            else
                break;
            parent = child;
        }
    }

    int size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

private:
    vector<int> data;
    Comp f;
};

class MedianFinder {
public:
    void addNum(int num) {
        if (firstHalf.empty() || firstHalf.top() >= num) {
            firstHalf.push(num);
            if (firstHalf.size() > secondHalf.size() + 1) {
                secondHalf.push(firstHalf.top());
                firstHalf.pop();
            }
        } else {
            secondHalf.push(num);
            if (firstHalf.size() < secondHalf.size()) {
                firstHalf.push(secondHalf.top());
                secondHalf.pop();
            }
        }
    }

    double findMedian() {
        double result = firstHalf.top();
        if (firstHalf.size() == secondHalf.size())
            result = result + (secondHalf.top() - result) / 2;
        return result;
    }

private:
    Heap<less<int>> firstHalf;
    Heap<greater<int>> secondHalf;
};
