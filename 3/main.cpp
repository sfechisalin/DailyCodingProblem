/*
 *
 * Suppose you are given a table of currency exchange rates,
 * represented as a 2D array. Determine whether there is a possible arbitrage: that is,
 * whether there is some sequence of trades you can make,
 * starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.
 */


/*
 *
 * Solution:
 * We can model the problem as a graph with the nodes as the currencies and the exchange rates as the edges.
 * Since our table is complete, the graph is also complete => we need to find a cycle whose edge weights product is
 * greater than 1.
 *
 * Optimization:
 * log(a * b) = log(a) + log(b).
 * - log(a * b) = - ( log(a) + log(b) )
 * so if we take the negative log of the edge weights [ - log(a * b * c * ... * ..) ],
 * the problem of finding a cumulative product that is greater
 * than 1 turns out into a problem of finding a negative sum cycle
 *
 * a * b * c * d > 1
 * log (a * b * c * d) > 0 | * (-1)
 * - log (a * b * c * d) < 0
 * - (log(a) + log(b) + log(c) + log(d)) = -log(a * b * c * d)
 * - log(x) < 0 if x is greater than 1, so that's why if we have a negative cost cycle,
 * it means that the product of the weighted edges is bigger than 1 => Bellman Ford
 */
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool possible(int n, vector<vector<int>> &exchangeRates) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                exchangeRates[i][j] = -log(exchangeRates[i][j]);

        int source = 0;
        vector<int> min_dist(n, 0x3f3f3f);
        min_dist[source] = 0;

        // relax edges n - 1 times
        for (int i = 0; i < n - 1; ++i)
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < n; ++y)
                    if (min_dist[x] > min_dist[y] + exchangeRates[x][y])
                        min_dist[x] = min_dist[y] + exchangeRates[x][y];

        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                if (min_dist[x] > min_dist[y] + exchangeRates[x][y])
                    return true;

        return false;
    }
};

int main() {

    return 0;
}
