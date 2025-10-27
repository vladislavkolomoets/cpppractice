class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1,
                              std::vector<std::string>& word2) {
        std::string res1{};
        for (const auto& word : word1) {
            res1 += word;
        }

        std::string res2{};
        for (const auto& word : word2) {
            res2 += word;
        }

        return res1 == res2;
    }
};