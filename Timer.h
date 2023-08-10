//
// Created by AnGa on 2023-05-27.
//

#ifndef LABB3_TIMER_H
#define LABB3_TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    void start();
    void stop();
    [[nodiscard]] double elapsedNanoseconds() const;

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point stop_time;
    bool is_running;

};


#endif //LABB3_TIMER_H
