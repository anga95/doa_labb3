//
// Created by AnGa on 2023-08-09.
//

#ifndef LABB3_MEASUREMENT_H
#define LABB3_MEASUREMENT_H


#include "SearchData.h"
#include "Timer.h"
#include <functional>
#include <string>
#include <vector>

using SearchFunction = std::function<int(const std::vector<int>&, int)>;

//struct SearchData{
//    std::string method;
//    int dataSize;
//    double timeTaken;
//    double standardDeviation;
//    int sampleCount;
//};

SearchData measure(const std::vector<int>& data, const std::vector<int>& target_values, SearchFunction searchFunction, const std::string& method_name, int samples = 10);
double calculateStandardDeviation(const std::vector<double>& samples);
int randomTargetPrimeNumber(std::vector<int>& primes);
#endif //LABB3_MEASUREMENT_H
