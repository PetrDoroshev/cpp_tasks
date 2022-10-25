#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>


double min(std::vector<double>& data);

double lq(std::vector<double>& data);

double median(std::vector<double>& data);

double mean(std::vector<double>& data);

double stddev(std::vector<double> data);

double uq(std::vector<double>& data);

double max(std::vector<double>& data);

std::vector<double> out(std::vector<double>& data);

void boxInfo(std::vector<double> data, int precision);

