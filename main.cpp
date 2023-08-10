#include <iostream>
#include "generate_primes.h"
#include "binary_search_tree.h"
#include "binary_search.h"
#include "linear_search.h"
#include "HashTable.h"
#include <random>
#include "SearchData.h"
#include "fileHandling.h"
#include "Measurement.h"


//int randomTargetPrimeNumber(std::vector<int>& arr){
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distr(0, arr.size() - 1);
//    return arr[distr(gen)];
//}

int main() {
    int number_of_primes = 100'000;
    std::vector<int> primes = generate_primes(number_of_primes);
    int primes_size = primes.size();
    int tenth_of_primes_size = primes_size / 10;
    int samples = 1000;


    std::cout << "starting searches..." << std::endl;

    std::vector<SearchData> search_results;
    for (int data_size = tenth_of_primes_size; data_size <= primes_size; data_size += tenth_of_primes_size) {
        std::cout << "Start " << data_size / tenth_of_primes_size << " of " << primes_size / tenth_of_primes_size << std::endl;
        std::vector<int> subset_of_primes(primes.begin(), primes.begin() + data_size);
        std::vector<int> target_values(samples);
        for (int target_value = 0; target_value < samples; ++target_value) {
            target_values[target_value] = randomTargetPrimeNumber(subset_of_primes);
        }

        HashTable hashTable(subset_of_primes);
        std::cout << "created hash table of: " << subset_of_primes.size() << " elements" << std::endl;
        BinarySearchTree binarySearchTree(subset_of_primes);
        std::cout << "created binary search tree of: " << subset_of_primes.size() << " elements" << std::endl;

        // Linear search
        search_results.push_back(measure(subset_of_primes,
                                         target_values,
                                         linearSearch,
                                         "Linear Search",
                                         samples));
        // Binary search
        search_results.push_back(measure(subset_of_primes,
                                         target_values,
                                         binarySearch,
                                         "Binary Search",
                                         samples));
        // Hash table search
        search_results.push_back(measure(subset_of_primes,
                                         target_values,
                                         [&](const std::vector<int>& data, int value) { return hashTable.search(value); },
                                         "Hash Table",
                                         samples));
        // Binary search tree search
        search_results.push_back(measure(subset_of_primes,
                                         target_values,
                                         [&](const std::vector<int>& data, int value) { return binarySearchTree.search(value) != nullptr ? 1 : 0; },
                                         "Binary Search Tree",
                                         samples));
        std::cout << "finished " << data_size / tenth_of_primes_size << " of " << primes_size / tenth_of_primes_size << std::endl << std::endl;
    }

    writeToFile(search_results);
    return 0;
}