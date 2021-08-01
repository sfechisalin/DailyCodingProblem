/*
 *
  Write a function that takes in a non-empty array of integers that are sorted
  in ascending order and returns a new array of the same length with the squares
  of the original integers also sorted in ascending order.
 */

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    int firstPositive = 0;
    int firstNegative;
    vector<int> result;

    while (array[firstPositive] < 0)
        ++firstPositive;

    firstNegative = firstPositive - 1;
    while (firstPositive < array.size() && firstNegative >= 0) {
        if (array[firstPositive] * array[firstPositive] < array[firstNegative] * array[firstNegative]) {
            result.push_back(array[firstPositive] * array[firstPositive]);
            firstPositive++;
        } else {
            result.push_back(array[firstNegative] * array[firstNegative]);
            firstNegative--;
        }
    }

    while (firstPositive < array.size()) {
        result.push_back(array[firstPositive] * array[firstPositive]);
        ++firstPositive;
    }

    while (firstNegative >= 0) {
        result.push_back(array[firstNegative] * array[firstNegative]);
        --firstNegative;
    }

    return result;
}
