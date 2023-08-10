//
// Created by AnGa on 2023-05-27.
//

#include "generate_primes.h"
std::vector<int> generate_primes(int number_of_primes){
    std::vector<int> primes;
    int current_number = 2;

    while (primes.size() < number_of_primes) {
        bool is_prime = true;
        for (int divisor = 2; divisor <= std::sqrt(current_number); ++divisor) {
            if (current_number % divisor == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(current_number);
        }
        current_number++;
    }

    return primes;
}
