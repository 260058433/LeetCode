#include <string>

using std::string;

class IntegerToRoman {
public:
    string intToRoman(int num) {
        /*
        if (num <= 0)
            return string();
        string result;
        while (num) {
            if (num >= 1000) {
                result.push_back('M');
                num -= 1000;
            } else if (num >= 900) {
                result.push_back('C');
                num += 100;
            } else if (num >= 500) {
                result.push_back('D');
                num -= 500;
            } else if (num >= 400) {
                result.push_back('C');
                num += 100;
            } else if (num >= 100) {
                result.push_back('C');
                num -= 100;
            } else if (num >= 90) {
                result.push_back('X');
                num += 10;
            } else if (num >= 50) {
                result.push_back('L');
                num -= 50;
            } else if (num >= 40) {
                result.push_back('X');
                num += 10;
            } else if (num >= 10) {
                result.push_back('X');
                num -= 10;
            } else if (num >= 9) {
                result.push_back('I');
                num += 1;
            } else if (num >= 5) {
                result.push_back('V');
                num -= 5; 
            } else if (num >= 4) {
                result.push_back('I');
                num += 1;
            } else if (num >= 1) {
                result.push_back('I');
                num -= 1;
            }
        }
        return result;
        */

        string thousand[] = {"", "M", "MM", "MMM"};
        string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousand[num / 1000] + hundred[num / 100 % 10] + ten[num / 10 % 10] + one[num % 10];
    }
};
