//
// Created by AnGa on 2023-05-28.
//

#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const std::vector<int> &primes) : root(nullptr) {
    buildBalancedTree(primes, 0, primes.size()-1);
}

void BinarySearchTree::insert(int value) {
    insert(value, root);
}

void BinarySearchTree::insert(int value, BinarySearchTreeNode*& node){
    if (node == nullptr){
        node = new BinarySearchTreeNode{value, nullptr, nullptr};
    }else if (value < node->data){
        insert(value, node->left); 
    }else if (value > node->data){
        insert(value, node->right);
    }
}

BinarySearchTreeNode* BinarySearchTree::search(const int value)  {
    return search(value, root);
}

BinarySearchTreeNode* BinarySearchTree::search(int value, BinarySearchTreeNode *node) const {
    if (node == nullptr || node->data == value) {
        return node;
    }
    if (value < node->data) {
        return search(value, node->left);
    }
    return search(value, node->right);
}

BinarySearchTree::~BinarySearchTree() {
    clear();
}
void BinarySearchTree::clear() {
    clear(root);
}
void BinarySearchTree::clear(BinarySearchTreeNode *node) {
    if (node != nullptr){
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
void BinarySearchTree::buildBalancedTree(const std::vector<int>& sorted_data, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        insert(sorted_data[mid]);
        buildBalancedTree(sorted_data, start, mid-1);
        buildBalancedTree(sorted_data, mid+1, end);
    }
}
