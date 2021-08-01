/*
  Write a function that takes in a Binary Search Tree (BST) and a target integer
  value and returns the closest value to that target value contained in the BST.
 */

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target, int &bestDiff) {
    if (tree == NULL)
        return INT_MAX - 2;

    int bestValue;
    if (tree->value > target) {
        bestValue = findClosestValueInBst(tree->left, target, bestDiff);
    } else {
        bestValue = findClosestValueInBst(tree->right, target, bestDiff);
    }

    if (abs(bestValue - target) < abs(tree->value - target))
    {
        bestDiff = abs(bestValue - target);
        return bestValue;
    }

    bestDiff = abs(tree->value - target);
    return tree->value;
}

int findClosestValueInBst(BST *tree, int target) {
    int bestDiff = INT_MAX - 2;
    return findClosestValueInBst(tree, target, bestDiff);
}
