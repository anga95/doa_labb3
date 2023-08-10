//
// Created by AnGa on 2023-05-28.
//

#include <iostream>
#include "linear_search.h"
#include "Timer.h"
#include "SearchData.h"

int linearSearch(const std::vector<int> &arr, int value) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

//SearchData measureLinearSearch(std::vector<int> &primes, int target_value){
//    Timer timer;
//    timer.start();
//    linearSearch(primes, target_value);
//    timer.stop();
//
//    SearchData data;
//    data.method = "Linear Search";
//    data.dataSize = primes.size();
//    data.timeTaken = timer.elapsedMilliseconds();
//    data.sampleCount = 1;
//    data.standardDeviation = 0;
//    return data;
//}