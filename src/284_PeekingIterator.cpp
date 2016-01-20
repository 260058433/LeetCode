#include <vector>

using std::vector;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        cur = 0;
        isValid = false;
    }

    int peek() {
        if (!isValid) {
            cur = Iterator::next();
            isValid = true;
        }
        return cur;
    }

    int next() {
        if (isValid) {
            isValid = false;
            return cur;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return isValid || Iterator::hasNext();
    }

private:
    int cur;
    bool isValid;
};
