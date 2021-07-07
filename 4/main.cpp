/*
 *Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make
 * the string valid (i.e. each open parenthesis is eventually closed). For example, given the string "()())()", you
 * should return 1. Given the string ")(", you should return 2, since we must remove all of them.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int edits_to_make_string_valid(string s) {
        int opened = 0;
        int to_be_removed = 0;
        for (int i = 0; s[i]; ++i)
        {
            if (s[i] == '(') {
                ++opened;
                continue;
            }

            --opened;
            if (opened < 0) {
                opened = 0;
                to_be_removed++;
            }
        }

        to_be_removed += opened;
        return to_be_removed;
    }
};

int main() {

    Solution s;

    cout << s.edits_to_make_string_valid("()())()");
    cout << "\n";
    cout << s.edits_to_make_string_valid(")(");
    return 0;
}
