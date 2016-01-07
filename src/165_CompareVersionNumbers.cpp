#include <string>

using std::string;

class CompareVersionNumbers {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m = version1.size(), n = version2.size();
        while (i < m || j < n) {
            int a = 0;
            while (i < m && version1[i] != '.')
                a = a * 10 + version1[i++] - '0';
            ++i;
            int b = 0;
            while (j < n && version2[j] != '.')
                b = b * 10 + version2[j++] - '0';
            ++j;
            if (a < b)
                return -1;
            else if (b < a)
                return 1;
        }
        return 0;
    }
};
