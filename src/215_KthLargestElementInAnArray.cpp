#include <vector>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstdlib>

using std::vector;
using std::invalid_argument;
using std::sort;
using std::priority_queue;
using std::greater;
using std::rand;
using std::swap;

class KthLargestElementInAnArray {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty() || k <= 0 || k > nums.size())
            throw invalid_argument("arg error");

        //sort the array
        //time O(n * log n), space O(1)
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        */

        //by priority_queue
        //time O(n * log k), space O(k);
        /*
        priority_queue<int, vector<int>, greater<int>> kth;
        for (int i = 0; i < k; ++i)
            kth.push(nums[i]);
        for (int i = k; i < nums.size(); ++i) {
            kth.push(nums[i]);
            kth.pop();
        }
        return kth.top();
        */

        //by partition
        //time best O(n) / worst O(n^2), space O(1)
        /*
        int begin = 0, end = nums.size();
        while (true) {
            int i = begin, j = end - 1;
            swap(nums[begin], nums[begin + rand() % (end - begin)]);
            int key = nums[begin];
            while (i < j) {
                while (i < j && nums[j] >= key)
                    --j;
                if (i < j)
                    nums[i++] = nums[j];
                while (i < j && nums[i] <= key)
                    ++i;
                if (i < j)
                    nums[j--] = nums[i];
            }
            nums[i] = key;
            if (end - i < k) {
                k = k - end + i;
                end = i;
            } else if (end - i > k) {
                begin = i + 1;
            } else {
                return key;
            }
        }
        */

        //by heap sort
        //time O(n + k * log n), space O(1)
        for (int i = nums.size() / 2 - 1; i >= 0; --i)
            heapAdjust(nums, i, nums.size());
        for (int i = 1; i < k; ++i) {
            swap(nums[0], nums[nums.size() - i]);
            heapAdjust(nums, 0, nums.size() - i);
        }
        return nums[0];
    }

private:
    void heapAdjust(vector<int> &heap, int node, int size) {
        while (node < size / 2) {
            int child = (node << 1) + 1;
            if (child < size - 1 && heap[child] < heap[child + 1])
                child += 1;
            if (heap[node] < heap[child]) {
                swap(heap[node], heap[child]);
                node = child;
            } else {
                break;
            }
        }
    }
};
