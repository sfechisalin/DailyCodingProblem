/*
 *
  Given two non-empty arrays of integers, write a function that determines
  whether the second array is a subsequence of the first one.

  A subsequence of an array is a set of numbers that aren't necessarily adjacent
  in the array but that are in the same order as they appear in the array. For
  instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4], and so do the numbers
  [2, 4]. Note that a single number in an array and the array itself are both valid subsequnces of the array.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int indexSecond = 0;
    int indexFirst = 0;
    int lengthSecond = sequence.size();
    int lengthFirst = array.size();

    while (indexFirst < lengthFirst && indexSecond < lengthSecond)
    {
        if (array[indexFirst] == sequence[indexSecond])
            ++indexSecond;
        ++indexFirst;
    }
    return indexSecond == lengthSecond;
}
