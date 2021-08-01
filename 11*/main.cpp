/*
 *
  Given an array of positive integers representing the values of coins in your
  possession, write a function that returns the minimum amount of change (the
  minimum sum of money) that you cannot create. The given coins can have
  any positive integer value and aren't necessarily unique (i.e., you can have
  multiple coins of the same value).


  For example, if you're given  coins = [1, 2, 5], the minimum amount of change that you cant create is 4. If you're
  given no coins, the minimum amount of change that you can't create is 1.
 */
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    sort(coins.begin(), coins.end());

    int change = 0;

    for (int i = 0; i < coins.size(); ++i) {
        if (change + 1 < coins[i])
            return change + 1;
        change += coins[i];
    }

    return change + 1;
}
