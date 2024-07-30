#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//背包问题
int maxValue(vector<int>& weight, vector<int>& value,int maxWeight) {
	vector<vector<int>>dp(weight.size(), vector<int>(maxWeight, 0));
	for (int i = 0; i < maxWeight; i++) {
		if (i < weight[0])
			dp[0][i] = 0;
		else
			dp[0][i] = value[i];
	}
	for (int i = 1; i < weight.size(); i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (j - weight[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[weight.size() - 1][maxWeight];
}
//class Solution {
//public:
//    int numTrees(int n) {
//        vector<int>dp(n + 1, 0);
//        dp[0] = 1, dp[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            for (int j = 1; j <= i; j++) {
//                dp[i] += dp[i - j] * dp[j - 1];
//            }
//        }
//        return dp[n];
//    }
//};
//class Solution {
//public:
//    int integerBreak(int n) {
//        vector<int>dp(n + 1);
//        dp[0] = 0, dp[1] = 0, dp[2] = 1;
//        for (int i = 3; i <= n; i++) {
//            for (int j = 1; j <= i / 2; j++) {
//                dp[i] = max(j * dp[i - j], dp[i]);
//            }
//        }
//        return dp[n];
//    }
//};
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        vector<vector<int>>dp(obstacleGrid.size()+1);
//        for (int i = 0; i < obstacleGrid.size(); i++) {
//            if (obstacleGrid[i][0] != 1)
//                dp[i][0] = 1;
//            else
//                dp[i][0] = 0;
//        }
//        for (int i = 0; i < obstacleGrid[0].size(); i++) {
//            if (obstacleGrid[0][i] != 1)
//                dp[i][0] = 1;
//            else
//                dp[i][0] = 0;
//        }
//        for (int i = 1; i < obstacleGrid.size(); i++) {
//            for (int j = 1; j < obstacleGrid[0].size(); j++) {
//                if (obstacleGrid[i][j] != 1)
//                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                else
//                    dp[i][j] = 0;
//            }
//        }
//        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
//    }
//};