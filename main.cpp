#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.size();
        const int n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = 0; i <= n1; i++){
            for (int j = 0; j <= n2; j++){
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(word1.at(i-1) == word2.at(j-1)) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    Solution s;
    string s1 = "horse";
    string s2 = "ros";
    cout << s.minDistance(s1, s2) << endl;
    return 0;
}
