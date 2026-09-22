#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int nodeValue);
};

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void clear();

    std::vector<int> inOrderTraversal() const;
    std::vector<int> preOrderTraversal() const;
    std::vector<int> postOrderTraversal() const;
    std::vector<int> breadthFirstTraversal() const;

    void printTreeByLevel() const;
    void printParentChildRelationships() const;

private:
    TreeNode *root_;

    void deleteSubtree(TreeNode *node);
    void insertRecursive(TreeNode *&current, int value);
    void inOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void preOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void postOrderRecursive(const TreeNode *current, std::vector<int> &values) const;
    void printTreeLevel(const std::vector<const TreeNode *> &levelNodes) const;
    void printParentChildRelationshipsRecursive(const TreeNode *current, const TreeNode *parent) const;
};

#endif // BINARY_SEARCH_TREE_H
