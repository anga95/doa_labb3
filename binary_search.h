//
// Created by AnGa on 2023-05-28.
//

#ifndef LABB3_BINARY_SEARCH_H
#define LABB3_BINARY_SEARCH_H

#include <vector>
#include "SearchData.h"

int binarySearch(const std::vector<int>& primes, int target_value);

int interpolation_search(const std::vector<int>& primes, int target_value);
//SearchData measureBinarySearch(std::vector<int> &primes, int target_value);
//SearchData measureInterpolationSearch(std::vector<int> &primes, int target_value);



#endif //LABB3_BINARY_SEARCH_H
