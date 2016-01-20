#include <algorithm>

using std::max;
using std::min;

class RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = 0;
        if (!(B >= H || D <= F || A >= G || C <= E)) {
            int x1 = max(A, E), x2 = min(C, G), y1 = max(B, F), y2 = min (D, H);
            area -= (x2 - x1) * (y2 - y1);
        }
        area += (C - A) * (D - B) + (G - E) * (H - F);
        return area;
    }
};
