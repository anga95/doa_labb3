//
// Created by AnGa on 2023-05-28.
//

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "fileHandling.h"
#include "SearchData.h"
#include <vector>

std::string getCurrentDateAndTime(){
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream currentDateAndTime;
    currentDateAndTime << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return currentDateAndTime.str();
}

void writeToFile(const std::vector<SearchData>& results) {
    std::string filename = "output/search_data_" + getCurrentDateAndTime() + ".csv";
    std::ofstream outPutFile(filename);


    outPutFile << "Algorithm,Data size,Time taken(ms),Stdev(ms),Samples" << std::endl;
    for (const auto& result : results) {
        outPutFile << result.method << ","
                   << result.dataSize << ","
                   << result.timeTaken / 1000.0<< ","
                   << result.standardDeviation / 1000.0 << ","
                   << result.sampleCount << ","
                   << std::endl;
    }
    outPutFile.close();
    std::cout << "results saved to: " << filename << std::endl;

    outPutFile.close();
}
