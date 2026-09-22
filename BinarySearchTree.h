#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>

// Represents one node in the binary search tree.
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int nodeValue);
};

// Binary search tree implementation that stores integer values.
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    // Inserts a value into the BST.
    void insert(int value);

    // Deletes every node in the tree and resets the root pointer.
    void clear();

    // Traversal results.
    std::vector<int> inOrderTraversal() const;
    std::vector<int> preOrderTraversal() const;
    std::vector<int> postOrderTraversal() const;
    std::vector<int> breadthFirstTraversal() const;

    // Tree display helpers.
    void printTreeByLevel() const;
    void printParentChildRelationships() const;

private:
    TreeNode *root_;

    void deleteSubtree(TreeNode *node);
    void insertRecursive(TreeNode *&current, int value);
    void inOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void preOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void postOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void printParentChildRelationshipsRecursive(const TreeNode *current,
                                                const TreeNode *parent) const;
};

#endif // BINARY_SEARCH_TREE_H
