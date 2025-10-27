class Solution {
public:
    int smallestEqual(std::vector<int>& nums) {
        std::vector<int> idxs;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 10 == nums[i]) {
                idxs.push_back(i);
            }
        }

        if (idxs.empty()) {
            return -1;
        } else {
            int target_index = idxs[0];

            for (const auto& idx : idxs) {
                if (idx < target_index)
                    target_index = idx;
            }

            return target_index;
        }
    }
};