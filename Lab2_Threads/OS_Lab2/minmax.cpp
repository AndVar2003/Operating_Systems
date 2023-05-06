#include <iostream>
#include <vector>
#include <thread>
#include "minmax.h"

constexpr std::chrono::duration<double, std::milli> MinMaxSleepTime = std::chrono::duration<double, std::milli>(7);
constexpr std::chrono::duration<double, std::milli> AverageSleepTime = std::chrono::duration < double, std::milli>(12);

void MinMax::Min_Max(std::vector<double>& Array, std::pair<double, double>& minmax)
{
    double min = Array[0];
    double max = Array[0];

    for (int i = 0; i < Array.size(); i++) {
        if (Array[i] < min)
        {
            std::this_thread::sleep_for(MinMaxSleepTime);
            min = Array[i];
        }
        if (Array[i] > max)
        {
            std::this_thread::sleep_for(MinMaxSleepTime);
            max = Array[i];
        }
    }

    std::cout << "Min Element: " << static_cast<int>(min) << std::endl;
    std::cout << "Max Element: " << static_cast<int>(max) << std::endl;

    minmax.first = min;
    minmax.second = max;

    return;
}

void MinMax::Average(std::vector<double>& Array, double& average)
{
    double sum = 0;
    for (int i = 0; i < Array.size(); ++i) {
        sum += Array[i];
        std::this_thread::sleep_for(AverageSleepTime);
    }

    average = sum / static_cast<double>(Array.size());
    std::cout << "Average value of Array: " << average << std::endl;

    return;
}

void MinMax::Change_Array(std::vector<double>& Array, std::pair<double, double> const& minmax, double const& average)
{
    int min_intVal = static_cast<int>(minmax.first);
    int max_intVal = static_cast<int>(minmax.second);

    for (int i = 0; i < Array.size(); i++)
    {
        int elem_intVal = static_cast<int>(Array[i]);

        if ((elem_intVal == min_intVal) || (elem_intVal == max_intVal))
        {
            Array[i] = average;
            std::cout << "{" << Array[i] << "} ";
        }
        else
        {
            std::cout << static_cast<int>(Array[i]) << " ";
        }
    }
}