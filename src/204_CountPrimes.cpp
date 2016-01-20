#include <vector>

using std::vector;

class CountPrimes {
public:
    int countPrimes(int n) {
        vector<bool> flags(n, true);
        vector<int> primes;
        for (int i = 2; i < n; ++i) {
            if (flags[i])
                primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                flags[i * primes[j]] = false;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};
