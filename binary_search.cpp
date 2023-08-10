//
// Created by AnGa on 2023-05-28.
//

#include "binary_search.h"
#include "SearchData.h"
#include "Timer.h"

int binarySearch(const std::vector<int> &primes, int target_value) {
    int low = 0;
    int high = primes.size() - 1;

    while (low <= high){
        int mid = (low + high) / 2;
        if (primes[mid] == target_value)
            return mid;
        else if (primes[mid] < target_value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int interpolation_search(const std::vector<int>& primes, int target_value){
    int low = 0;
    int high = primes.size() - 1;

    while (low <= high && target_value >= primes[low] && target_value <= primes[high]){
        if (low == high){
            if(primes[low] == target_value){
                return -1;
            }
        }
        int pos = low + (((double)(high-low) / (primes[high] - primes[low])) * (target_value - primes[low]));

        if (primes[pos] == target_value){
            return pos;
        }
        if (primes[pos] < target_value){
            low = pos + 1;
        }
        else{
            high = pos - 1;
        }
    }
    return -1;
}
//
//SearchData measureBinarySearch(std::vector<int> &primes, int target_value){
//    Timer timer;
//    timer.start();
//    binarySearch(primes, target_value);
//    timer.stop();
//
//    SearchData data;
//    data.method = "Binary Search";
//    data.dataSize = primes.size();
//    data.timeTaken = timer.elapsedMilliseconds();
//    return data;
//}
//SearchData measureInterpolationSearch(std::vector<int> &primes, int target_value){
//    Timer timer;
//    timer.start();
//    interpolation_search(primes, target_value);
//    timer.stop();
//
//    SearchData data;
//    data.method = "Interpolation Search";
//    data.dataSize = primes.size();
//    data.timeTaken = timer.elapsedMilliseconds();
//    return data;
//}