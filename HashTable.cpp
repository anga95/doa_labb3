//
// Created by AnGa on 2023-05-29.
//
#include "HashTable.h"

HashTable::HashTable(const std::vector<int>& data) : reserved_size(data.size() * 2) {
    table.resize(reserved_size);
    for (int value : data){
        insert(value);
    }
}

void HashTable::insert(int data){
    int hash = data % reserved_size;
    auto& item = table[hash];
    auto new_node = std::make_unique<HashTableNode>();
    new_node->data = data;
    new_node->next = std::move(item);
    item = std::move(new_node);
}
int HashTable::search(int value){
    int hash = value % reserved_size;

    HashTableNode* node = table[hash].get();
    while(node != nullptr){
        if(node->data == value){
            return node->data;
        }
        node = node->next.get();
    }
    return -1;
}

//SearchData measureHashTable(std::vector<int> &primes, int target_value) {
//    HashTable hashTable(primes);
//
//    Timer timer;
//    timer.start();
//    hashTable.search(target_value);
//    timer.stop();
//
//    SearchData data;
//    data.method = "Hash Table";
//    data.dataSize = primes.size();
//    data.timeTaken = timer.elapsedMilliseconds();
//    return data;
//}