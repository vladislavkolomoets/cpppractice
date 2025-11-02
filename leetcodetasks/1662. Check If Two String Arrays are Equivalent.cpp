class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1,
                              std::vector<std::string>& word2) {

        int arrIdx1{}, arrIdx2{};
        int symIdx1{}, symIdx2{};

        while (arrIdx1 < word1.size() && arrIdx2 < word2.size()) {
            if (word1[arrIdx1][symIdx1] != word2[arrIdx2][symIdx2]) {
                return false;
            }

            symIdx1++;
            symIdx2++;

            if (symIdx1 == word1[arrIdx1].size()) {
                arrIdx1++;
                symIdx1 = 0;
            }

            if (symIdx2 == word2[arrIdx2].size()) {
                arrIdx2++;
                symIdx2 = 0;
            }
        }

        return arrIdx1 == word1.size() && arrIdx2 == word2.size();;
    }
};