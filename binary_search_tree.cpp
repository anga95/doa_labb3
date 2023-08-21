//
// Created by AnGa on 2023-05-28.
//

#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const std::vector<int> &primes) : root(nullptr) {
    for (int value : primes){
        insert(value);
    }
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

//SearchData BinarySearchTree::measureBinarySearchTree(std::vector<int> &primes, int target_value) {
//    Timer timer;
//    BinarySearchTree tree(primes);
//    timer.start();
//    BinarySearchTreeNode* node = tree.search(target_value);
//    timer.stop();
//    return SearchData{timer.getDuration(), node != nullptr};
//}
