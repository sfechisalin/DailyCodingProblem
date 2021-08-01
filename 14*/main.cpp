/*
  The distance between a node in a Binary Tree and the tree's root is called the
  node's depth.

  Write a function that takes in a Binary Tree and returns the sum of its nodes'
  depths.
 */

using namespace std;

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

int nodeDepths(BinaryTree *root, int depth) {
    if (!root) {
        return 0;
    }

    return depth + nodeDepths(root->left, depth + 1) + nodeDepths(root->right, depth + 1);
}

int nodeDepths(BinaryTree *root) {
    return nodeDepths(root, 0);
}
