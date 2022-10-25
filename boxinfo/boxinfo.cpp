#include "boxinfo.h"


double min(std::vector<double>& data){

    double lower_q = lq(data);
    double upper_q = uq(data);

    return lower_q - 1.5 * (upper_q - lower_q);
}

double lq(std::vector<double>& data){

    std::vector<double> half = {data.begin(), data.begin() + data.size() / 2 - 1};
    return median(half);
}

double median(std::vector<double>& data){

    if (data.size() % 2 != 0) {
        return data[data.size() / 2];
    }
    else {
        return (data[data.size() / 2] + data[data.size() / 2 + 1]) / 2;
    }
}

double mean(std::vector<double>& data) {

    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

double stddev(std::vector<double> data){

    double m = mean(data);
    std::for_each(data.begin(), data.end(), [m](double& x) { x = pow(x - m, 2); } );

    return sqrt(std::accumulate(data.begin(), data.end(), 0.0) / (data.size() - 1));
}

double uq(std::vector<double>& data){

    std::vector<double> half = {data.end() - data.size() / 2, data.end()};
    return median(half);
}

double max(std::vector<double>& data){

    double lower_q = lq(data);
    double upper_q = uq(data);

    return upper_q + 1.5 * (upper_q - lower_q);
}

std::vector<double> out(std::vector<double>& data){

    double left = min(data);
    double right = max(data);

    std::vector<double> out;
    std::copy_if(data.begin(), data.end(), std::back_inserter(out), 
                [left, right] (double x) { return (x < left) || (x > right); });

    return out;
}

void boxInfo(std::vector<double> data, int precision){

    std::sort(data.begin(), data.end());

    std::cout.precision(precision);

    std::cout << std::setw(10) << std::left << "min: " << std::scientific << min(data) << std::endl;
    std::cout << std::setw(10) << std::left << "lq: " << std::scientific << lq(data) << std::endl;
    std::cout << std::setw(10) << std::left << "median: " << std::scientific << median(data) << std::endl;
    std::cout << std::setw(10) << std::left << "mean: " << std::scientific << mean(data) << std::endl;
    std::cout << std::setw(10) << std::left << "stddev: " << std::scientific << stddev(data) << std::endl;
    std::cout << std::setw(10) << std::left << "uq: " << std::scientific << uq(data) << std::endl;
    std::cout << std::setw(10) << std::left << "max: " << std::scientific << max(data) << std::endl;
    std::cout << std::setw(10) << std::left << "max: ";

    for (auto &x: out(data)){
        std::cout << std::scientific << x << ' ';
    }
    std::cout << std::endl;
    
    
}
