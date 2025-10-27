class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        std::vector<int> wealths(accounts.size());

        for (int i = 0; i < accounts.size(); i++) {
            int wealth = 0;

            for (int j = 0; j < accounts[0].size(); j++) {
                wealth += accounts[i][j];
            }

            wealths.push_back(wealth);
        }

        int max_wealth = wealths[0];

        for (const auto& wealth : wealths) {
            if (wealth > max_wealth)
                max_wealth = wealth;
        }

        return max_wealth;
    }
};