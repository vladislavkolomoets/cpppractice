class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> result(n * 2);

        for (int j = 0, i = 0; j < n; i += 2, j++) {
            result[i] = nums[j];
            result[i + 1] = nums[j + n];
        }

        return result;
    }
};