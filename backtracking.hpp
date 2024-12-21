#pragma once
#include <vector>

inline std::vector<std::vector<int>> backtracking(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    if (nums.size() == 1) {
        result.push_back(nums);
        return result;
    }

    for (int i = 0; i < nums.size(); i++) {
        int fixed = nums[i];
        std::vector<int> remaining = nums;
        remaining.erase(remaining.begin() + i);

        std::vector<std::vector<int>> permutations = backtracking(remaining);

        for (auto& perm : permutations) {
            perm.insert(perm.begin(), fixed);
            result.push_back(perm);
        }
    }

    return result;
}
