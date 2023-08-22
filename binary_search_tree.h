//
// Created by AnGa on 2023-05-28.
//

#ifndef LABB3_BINARY_SEARCH_TREE_H
#define LABB3_BINARY_SEARCH_TREE_H
#include "SearchData.h"
#include <vector>

struct BinarySearchTreeNode {
    int data;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    explicit BinarySearchTree(const std::vector<int>& primes);
    ~BinarySearchTree();

    void insert(int value);
    BinarySearchTreeNode* search(const int value) ;
    void clear();
//    SearchData measureBinarySearchTree(std::vector<int> &primes, int target_value);


private:
    BinarySearchTreeNode* root;
    void insert(int value, BinarySearchTreeNode*& node);
    BinarySearchTreeNode* search(int value, BinarySearchTreeNode* node) const;
    void clear(BinarySearchTreeNode* node);
    void buildBalancedTree(const std::vector<int>& sorted_data, int start, int end);
};



#endif //LABB3_BINARY_SEARCH_TREE_H
