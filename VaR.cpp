#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double calculateVaR(const std::vector<double>& portfolioReturns, double confidenceLevel) {
    std::vector<double> sortedReturns = portfolioReturns;
    std::sort(sortedReturns.begin(), sortedReturns.end());

    int index = static_cast<int>((1 - confidenceLevel) * sortedReturns.size());
    return -sortedReturns[index];
}

int main() {
    std::vector<double> portfolioReturns = { 0.02, -0.01, 0.03, -0.05, 0.04, -0.02, 0.01, -0.03 };
    double confidenceLevel = 0.95;

    double var = calculateVaR(portfolioReturns, confidenceLevel);

    std::cout << "Value at Risk (VaR) at " << confidenceLevel * 100 << "% confidence level: " << var << std::endl;

    return 0;
}