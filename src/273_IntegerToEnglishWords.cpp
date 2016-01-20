#include <string>
#include <vector>

using std::string;
using std::vector;

class IntegerToEnglishWords {
public:
    string numberToWords(int num) {
        if (num == 0)
            return string("Zero");
        string result;
        int i = 0;
        while (num) {
            if (num % 1000)
                result = hundreds(num % 1000) + thousands[i] + " " + result;
            ++i;
            num /= 1000;
        }
        result.pop_back();
        return result;
    }

private:
    string hundreds(int num) {
        string result;
        if (num / 100)
            result = belowTwenty[num / 100] + " Hundred ";
        if (num % 100 < 20) {
            result += belowTwenty[num % 100];
        } else {
            result += tens[num % 100 / 10];
            result.push_back(' ');
            result += belowTwenty[num % 10];
        }
        while (!result.empty() && result.back() == ' ')
            result.pop_back();
        return result;
    }

    vector<string> belowTwenty{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", " Thousand", " Million", " Billion"};
};
