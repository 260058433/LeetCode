#include <vector>

using std::vector;

class MedianOfTwoSortedArrays {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0;
        }
        int n1 = nums1.size(), n2 = nums2.size();
        int num = (n1 + n2 + 1) / 2;
        int b1 = 0, b2 = 0;
        while (num != 1 && b1 != n1 && b2 != n2) {
            int m1 = num / 2;
            int m2 = num - m1;
            if (n1 - b1 < m1) {
                m1 = n1 - b1;
                m2 = num - m1;
            } else if (n2 - b2 < m2) {
                m2 = n2 - b2;
                m1 = num - m2;
            }
            if (nums1[b1 + m1 - 1] < nums2[b2 + m2 - 1]) {
                num -= m1;
                b1 += m1;
            } else if (nums2[b2 + m2 - 1] < nums1[b1 + m1 - 1]) {
                num -= m2;
                b2 += m2;
            } else {
                b1 = b1 + m1 - 1;
                b2 += m2;
                break;
            }    
        }
        int a1, a2;
        if (b1 == n1) {
            a1 = a2 = nums2[b2 + num - 1];
            if ((n1 + n2) % 2 == 0)
                a2 = nums2[b2 + num];
        }
        else if (b2 == n2) {
            a1 = a2 = nums1[b1 + num - 1];
            if ((n1 + n2) % 2 == 0)
                a2 = nums1[b1 + num];
        } else {
            a1 = a2 = nums1[b1] < nums2[b2] ? nums1[b1++] : nums2[b2++];
            if (n1 % 2 == n2 % 2) {
                if (b1 == n1)
                    a2 = nums2[b2];
                else if (b2 == n2)
                    a2 = nums1[b1];
                else
                    a2 = nums1[b1] < nums2[b2] ? nums1[b1] : nums2[b2];
            }
        }
        return a1 + (a2 - a1) / 2;
    }
};
