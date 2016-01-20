bool isBadVersion(int version);

class FirstBadVersion {
public:
    int firstBadVersion(int n) {
        int b = 1, e = n;
        while (b <= e) {
            int m = b + (e - b) / 2;
            if (isBadVersion(m))
                e = m - 1;
            else
                b = m + 1;
        }
        return b;
    }
};
