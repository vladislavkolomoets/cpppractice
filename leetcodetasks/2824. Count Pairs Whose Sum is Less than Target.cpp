class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        int counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target && i < j) {
                    counter++;
                }
            }
        }
        return counter;
    }
};