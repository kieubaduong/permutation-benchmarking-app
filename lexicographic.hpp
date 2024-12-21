#pragma once
#include <vector>
#include <algorithm>
#include <ranges>

inline bool nextPermutation(std::vector<int>& nums) {
    auto n = static_cast<int>(nums.size());
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i < 0) {
        return false;
    }

    int j = n - 1;
    while (nums[j] <= nums[i]) {
        --j;
    }

    std::swap(nums[i], nums[j]);
    std::reverse(nums.begin() + i + 1, nums.end());
    return true;
}

inline std::vector<std::vector<int>> lexicographicOrder(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::ranges::sort(nums);
    result.push_back(nums);

    while (nextPermutation(nums)) {
        result.push_back(nums);
    }

    return result;
}
