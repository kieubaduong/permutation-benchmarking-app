#pragma once
#include <vector>

inline void dfsHelper(const std::vector<int>& nums, std::vector<bool>&& used, std::vector<int>&& path, std::vector<std::vector<int>>& ans) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) {
            continue;
        }
        
        used[i] = true;
        path.push_back(nums[i]);
        dfsHelper(nums, std::move(used), std::move(path), ans);
        path.pop_back();
        used[i] = false;
    }
}

inline std::vector<std::vector<int>> dfsPermute(const std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    dfsHelper(nums, std::vector<bool>(nums.size()), {}, ans);
    return ans;
}
