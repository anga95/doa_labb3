//
// Created by AnGa on 2023-05-27.
//

#include "Timer.h"

Timer::Timer() : start_time(), stop_time(), is_running(false) {}

void Timer::start() {
    start_time = std::chrono::high_resolution_clock::now();
    is_running = true;
}

void Timer::stop() {
    stop_time = std::chrono::high_resolution_clock::now();
    is_running = false;
}

double Timer::elapsedNanoseconds() const {
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;

    if (is_running) {
        end_time = std::chrono::high_resolution_clock::now();
    } else {
        end_time = stop_time;
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

