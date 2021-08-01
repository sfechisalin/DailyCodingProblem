/*
  Write a function that takes in a Binary Tree and returns a list of its branch
  sums ordered from leftmost branch sum to rightmost branch sum.

  A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree
  branch is a path of nodes in a tree that starts at the root node and ends at
  any leaf node.
 */

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void collectSums(BinaryTree *root, int runningSum, vector<int> &accumulator) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        accumulator.push_back(runningSum + root->value);
        return;
    }

    collectSums(root->left, runningSum + root->value, accumulator);
    collectSums(root->right, runningSum + root->value, accumulator);
}

vector<int> branchSums(BinaryTree *root) {
    vector<int> accumulator;
    collectSums(root, 0, accumulator);
    return accumulator;
}
