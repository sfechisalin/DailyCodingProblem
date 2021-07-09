/*
 * Given an integer, find the next permutation of it in absolute order. For example, given 48975, the next permutation would be 49578.
 */


#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
public:
    string nextNumber(string digits) {
        int digits_size = digits.size();
        int posDigitToReplace = digits_size - 1;

        while (posDigitToReplace >= 1 && digits[posDigitToReplace] < digits[posDigitToReplace - 1])
            --posDigitToReplace;

        if (posDigitToReplace == 0) {
            cout << "No next configuration available!";
            return 0;
        }

        int swap = posDigitToReplace--;
        while (swap <= digits_size - 1 && digits[swap] >= digits[posDigitToReplace])
            ++swap;

        char aux = digits[posDigitToReplace];
        digits[posDigitToReplace] = digits[--swap];
        digits[swap] = aux;

        for (int i = posDigitToReplace + 1, j = digits_size - 1; i < j; ++i, --j) {
            aux = digits[i];
            digits[i] = digits[j];
            digits[j] = aux;
        }
        
        return digits;
    }
};

int main() {

    Solution s;
    cout << s.nextNumber("48975");
    return 0;
}
