//
// Created by AnGa on 2023-08-09.
//

#include <numeric>
#include <random>
#include <iostream>
#include "Measurement.h"
volatile int resultCheck = 0;
SearchData measure(const std::vector<int>& data, const std::vector<int>& target_values, SearchFunction searchFunction, const std::string& method_name, int samples) {

    std::vector<double> samplesVector;
    for (int sample = 0; sample < samples; sample++) {
        Timer timer;
        timer.start();
        int index = searchFunction(data, target_values[sample]);
        timer.stop();
        samplesVector.push_back(timer.elapsedNanoseconds());

        resultCheck += data[index];

    }

    SearchData result;
    result.method = method_name;
    result.dataSize = data.size();
    result.timeTaken = std::accumulate(samplesVector.begin(), samplesVector.end(), 0.0) / samples;
    result.sampleCount = samples;
    result.standardDeviation = calculateStandardDeviation(samplesVector);;

    return result;
}
int randomTargetPrimeNumber(std::vector<int>& primes){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, primes.size() - 1);
    return primes[distr(gen)];
}
double calculateStandardDeviation(const std::vector<double>& samples){
    double sum = std::accumulate(samples.begin(), samples.end(), 0.0);
    double mean = sum / samples.size();

    double squardDifferenceSum = double();

    for (const double& sample : samples) {
        squardDifferenceSum += std::pow(sample - mean, 2);
    }

    double variance = squardDifferenceSum / samples.size();
    double standardDeviation = std::sqrt(variance);

    return standardDeviation;
}