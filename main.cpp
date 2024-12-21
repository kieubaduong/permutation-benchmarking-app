#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include "backtracking.hpp"
#include "dfs.hpp"
#include "factorial.hpp"
#include "heap.hpp"
#include "lexicographic.hpp"

using namespace std;
using namespace chrono;

vector<int> generateRandomVector(int size, int minValue, int maxValue) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minValue, maxValue);

    for (int i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }

    return vec;
}

void printBenchmarkResults(const vector<int>& datasetSizes, const vector<double>& timesBacktracking, const vector<double>& timesDFS, const vector<double>& timesFactorial, const vector<double>& timesHeap, const vector<double>& timesLexicographic) {
    const int columnWidth = 24;
    cout << left << setw(columnWidth) << "Dataset Size"
        << setw(columnWidth) << "backtracking (ms)"
        << setw(columnWidth) << "dfsPermute (ms)"
        << setw(columnWidth) << "factorialPermute (ms)"
        << setw(columnWidth) << "heapPermute (ms)"
        << setw(columnWidth) << "lexicographicOrder (ms)" << endl;
    cout << string(columnWidth * 7, '-') << endl;
    for (size_t i = 0; i < datasetSizes.size(); ++i) {
        cout << setw(columnWidth) << datasetSizes[i]
            << setw(columnWidth) << timesBacktracking[i]
            << setw(columnWidth) << timesDFS[i]
            << setw(columnWidth) << timesFactorial[i]
            << setw(columnWidth) << timesHeap[i]
            << setw(columnWidth) << timesLexicographic[i] << endl;
    }
}

int main() {
    vector<int> datasetSizes = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    vector<double> timesBacktracking;
    vector<double> timesDFS;
    vector<double> timesFactorial;
    vector<double> timesHeap;
    vector<double> timesLexicographic;

    for (int size : datasetSizes) {
        vector<int> nums = generateRandomVector(size, -10, 10);

        auto start = high_resolution_clock::now();
        backtracking(nums);
        auto end = high_resolution_clock::now();
        timesBacktracking.push_back(static_cast<double>(duration_cast<milliseconds>(end - start).count()));

        start = high_resolution_clock::now();
        dfsPermute(nums);
        end = high_resolution_clock::now();
        timesDFS.push_back(static_cast<double>(duration_cast<milliseconds>(end - start).count()));

        start = high_resolution_clock::now();
        factorialPermute(nums);
        end = high_resolution_clock::now();
        timesFactorial.push_back(static_cast<double>(duration_cast<milliseconds>(end - start).count()));

        start = high_resolution_clock::now();
        heapPermute(nums);
        end = high_resolution_clock::now();
        timesHeap.push_back(static_cast<double>(duration_cast<milliseconds>(end - start).count()));

        start = high_resolution_clock::now();
        lexicographicOrder(nums);
        end = high_resolution_clock::now();
        timesLexicographic.push_back(static_cast<double>(duration_cast<milliseconds>(end - start).count()));
    }

    printBenchmarkResults(datasetSizes, timesBacktracking, timesDFS, timesFactorial, timesHeap, timesLexicographic);

    return 0;
}
