#include "BinarySearchTree.h"

#include <iostream>
#include <queue>
#include <vector>

TreeNode::TreeNode(int nodeValue)
    : value(nodeValue), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    clear();
}

void BinarySearchTree::insert(int value)
{
    insertRecursive(root_, value);
}

void BinarySearchTree::clear()
{
    deleteSubtree(root_);
    root_ = nullptr;
}

std::vector<int> BinarySearchTree::inOrderTraversal() const
{
    std::vector<int> values;
    inOrderRecursive(root_, values);
    return values;
}

std::vector<int> BinarySearchTree::preOrderTraversal() const
{
    std::vector<int> values;
    preOrderRecursive(root_, values);
    return values;
}

std::vector<int> BinarySearchTree::postOrderTraversal() const
{
    std::vector<int> values;
    postOrderRecursive(root_, values);
    return values;
}

std::vector<int> BinarySearchTree::breadthFirstTraversal() const
{
    std::vector<int> values;

    if (root_ == nullptr)
    {
        return values;
    }

    std::queue<const TreeNode *> nodeQueue;
    nodeQueue.push(root_);

    while (!nodeQueue.empty())
    {
        const TreeNode *current = nodeQueue.front();
        nodeQueue.pop();

        values.push_back(current->value);

        if (current->left != nullptr)
        {
            nodeQueue.push(current->left);
        }
        if (current->right != nullptr)
        {
            nodeQueue.push(current->right);
        }
    }

    return values;
}

void BinarySearchTree::printTreeByLevel() const
{
    if (root_ == nullptr)
    {
        std::cout << "The tree is empty.\n";
        return;
    }

    std::queue<const TreeNode *> nodeQueue;
    nodeQueue.push(root_);
    int level = 0;

    while (!nodeQueue.empty())
    {
        int levelSize = static_cast<int>(nodeQueue.size());
        std::vector<const TreeNode *> currentLevel;

        std::cout << "Level " << level << ": ";

        for (int i = 0; i < levelSize; ++i)
        {
            const TreeNode *current = nodeQueue.front();
            nodeQueue.pop();
            currentLevel.push_back(current);
            std::cout << current->value;

            if (i < levelSize - 1)
            {
                std::cout << " ";
            }

            if (current->left != nullptr)
            {
                nodeQueue.push(current->left);
            }
            if (current->right != nullptr)
            {
                nodeQueue.push(current->right);
            }
        }

        std::cout << '\n';
        ++level;
    }
}

void BinarySearchTree::printParentChildRelationships() const
{
    if (root_ == nullptr)
    {
        std::cout << "The tree is empty.\n";
        return;
    }

    std::cout << "Parent -> Child relationships:\n";
    printParentChildRelationshipsRecursive(root_, nullptr);
}

void BinarySearchTree::deleteSubtree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

void BinarySearchTree::insertRecursive(TreeNode *&current, int value)
{
    if (current == nullptr)
    {
        current = new TreeNode(value);
        return;
    }

    if (value < current->value)
    {
        insertRecursive(current->left, value);
    }
    else
    {
        insertRecursive(current->right, value);
    }
}

void BinarySearchTree::inOrderRecursive(const TreeNode *current, std::vector<int> &values) const
{
    if (current == nullptr)
    {
        return;
    }

    inOrderRecursive(current->left, values);
    values.push_back(current->value);
    inOrderRecursive(current->right, values);
}

void BinarySearchTree::preOrderRecursive(const TreeNode *current, std::vector<int> &values) const
{
    if (current == nullptr)
    {
        return;
    }

    values.push_back(current->value);
    preOrderRecursive(current->left, values);
    preOrderRecursive(current->right, values);
}

void BinarySearchTree::postOrderRecursive(const TreeNode *current, std::vector<int> &values) const
{
    if (current == nullptr)
    {
        return;
    }

    postOrderRecursive(current->left, values);
    postOrderRecursive(current->right, values);
    values.push_back(current->value);
}

void BinarySearchTree::printParentChildRelationshipsRecursive(const TreeNode *current,
                                                              const TreeNode *parent) const
{
    if (current == nullptr)
    {
        return;
    }

    if (parent != nullptr)
    {
        std::cout << parent->value << " -> " << current->value << '\n';
    }
    else
    {
        std::cout << "Root: " << current->value << '\n';
    }

    printParentChildRelationshipsRecursive(current->left, current);
    printParentChildRelationshipsRecursive(current->right, current);
}
