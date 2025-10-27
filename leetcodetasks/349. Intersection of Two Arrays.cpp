class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
        std::vector<int> intersections{};

        for (const auto& num1 : nums1) {
            for (const auto& num2 : nums2) {
                if (num1 == num2)
                    intersections.push_back(num2);
            }
        }

        std::set<int> unique_elements(intersections.begin(),
                                      intersections.end());

        return std::vector<int>(unique_elements.begin(), unique_elements.end());
    }
};