/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() < 2) return profit;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i]-prices[i-1] > 0) {
                profit = profit + prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
// @lc code=end

