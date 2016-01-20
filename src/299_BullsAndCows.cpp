#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class BullsAndCows {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        vector<int> counts(10);
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                if (counts[secret[i] - '0']++ < 0) 
                    ++cow;
                if (counts[guess[i] - '0']-- > 0)
                    ++cow;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
