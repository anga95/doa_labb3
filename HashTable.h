//
// Created by AnGa on 2023-05-28.
//

#ifndef LABB3_HASHTABLE_H
#define LABB3_HASHTABLE_H


#include <memory>
#include <vector>
#include "HashTable.h"
#include "Timer.h"
#include "SearchData.h"

struct HashTableNode {
    int data;
    std::unique_ptr<HashTableNode> next;
};

class HashTable {
private:
    std::vector<std::unique_ptr<HashTableNode>> table;
    int reserved_size;
    int getMaxDepth() const;

public:
    HashTable(const std::vector<int>& primes);
    void insert(int data);
    int search(int value);
//    SearchData measureHashTable(std::vector<int> &primes, int target_value);
};


#endif //LABB3_HASHTABLE_H

