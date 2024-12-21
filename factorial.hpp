#pragma once
#include <vector>

inline void generatePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result, int& resultIndex) {
    if (start == nums.size()) {
        result[resultIndex] = nums;
        resultIndex++;
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        std::swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result, resultIndex);
        std::swap(nums[start], nums[i]);
    }
}

inline int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

inline std::vector<std::vector<int>> factorialPermute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current(nums.size());
    int resultIndex = 0;
    int totalPermutations = factorial(static_cast<int>(nums.size()));
    result.resize(totalPermutations, std::vector<int>(nums.size()));
    generatePermutations(nums, 0, result, resultIndex);
    return result;
}
