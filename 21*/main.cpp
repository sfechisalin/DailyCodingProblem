/*
  Write a function that takes in a "special" array and returns its product sum.

  A "special" array is a non-empty array that contains either integers or other
  "special" arrays. The product sum of a "special" array is the sum of its
  elements, where "special" arrays inside it are summed themselves and then
  multiplied by their level of depth.

  The depth of a "special" array is how far nested it is. For instance, the
  depth of [] is 1; ; the depth of the inner array in [[]] is 2; the depth of the innermost array in [[[]]] is 3.
  Therefore, the product sum of [x, y] is x + y; the product sum of [x, [y, z]] is x + 2 * (y + z);
  the product sum of [x, [y, [z]]] is x + 2 * (y + 3z)
 */

#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)

int productSum(vector<any> array, int depth) {
    int sum = 0;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i].type() == typeid(int))
            sum += depth * any_cast<int>(array[i]);
        else
            sum += depth * productSum(any_cast<vector<any>>(array[i]), depth + 1);
    }
    return sum;
}

int productSum(vector<any> array) {
    return productSum(array, 1);
}
