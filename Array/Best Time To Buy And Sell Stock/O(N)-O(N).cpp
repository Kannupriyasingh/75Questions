// Time Complexity = O(N)
// Space Complexity = O(1)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minSoFar = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            minSoFar = min(minSoFar, prices[i]);

          // if the minSoFar is less than the current stock prices, that means we have a chance to buy at minSoFar price and sell at current stock price to make profit
            if(minSoFar < prices[i]) {  
                profit = max(profit, (prices[i] - minSoFar));
            }
        }
        
        return profit;
    }
};


/*
Input : [7,1,5,3,6,4]
Output : 5
*/
