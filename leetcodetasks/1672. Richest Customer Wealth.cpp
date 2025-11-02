class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max_wealth = 0;

        for (const auto& customer_account : accounts) {
            int wealth = 0;

            for (int money : customer_account) {
                wealth += money;
            }

            max_wealth = std::max(max_wealth, wealth);
        }

        return max_wealth;
    }
};