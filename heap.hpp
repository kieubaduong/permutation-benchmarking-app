#pragma once
#include <vector>

inline void heapPermutation(std::vector<int>& nums, int size, std::vector<std::vector<int>>& result) {
    if (size == 1) {
        result.push_back(nums);
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(nums, size - 1, result);

        if (size % 2 == 1) {
            std::swap(nums[0], nums[size - 1]);
        } else {
            std::swap(nums[i], nums[size - 1]);
        }
    }
}

inline std::vector<std::vector<int>> heapPermute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    heapPermutation(nums, static_cast<int>(nums.size()), result);
    return result;
}
