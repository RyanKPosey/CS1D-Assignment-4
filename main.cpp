#include "BinarySearchTree.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace
{

    void printVector(const std::string &label, const std::vector<int> &values)
    {
        std::cout << label << ": ";
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            std::cout << values[i];
            if (i + 1 < values.size())
            {
                std::cout << ", ";
            }
        }
        std::cout << '\n';
    }

} // namespace

int main()
{
    std::cout << "Assignment 4 - Binary Trees\n";
    std::cout << "==========================\n\n";

    const int values[] = {49, 9, 59, 288, 19, 13, 888, 77, 25, 109,
                          55, 118, 89, 33, 1001, 18, 44, 88, 12, 24};

    BinarySearchTree tree;

    for (int value : values)
    {
        tree.insert(value);
    }

    std::cout << "Values inserted into the BST:\n";
    for (std::size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        std::cout << values[i];
        if (i + 1 < sizeof(values) / sizeof(values[0]))
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n\n";

    printVector("In-order traversal", tree.inOrderTraversal());
    printVector("Pre-order traversal", tree.preOrderTraversal());
    printVector("Post-order traversal", tree.postOrderTraversal());
    printVector("Breadth-first traversal", tree.breadthFirstTraversal());
    std::cout << '\n';

    std::cout << "Tree printed by level:\n";
    tree.printTreeByLevel();
    std::cout << '\n';

    tree.printParentChildRelationships();
    std::cout << '\n';

    return 0;
}
