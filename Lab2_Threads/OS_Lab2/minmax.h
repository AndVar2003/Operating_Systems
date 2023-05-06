#pragma once
#ifndef HeadEr
#define HeadEr
#include <iostream>
#include <thread>
#include <vector>

class MinMax
{
public:

    static void Min_Max(std::vector<double>& Array, std::pair<double, double>& minmax);

    static void Average(std::vector<double>& Array, double& average);

    static void Change_Array(std::vector<double>& Array, std::pair<double, double> const& minmax, double const& average);
};

#endif //HeadEr