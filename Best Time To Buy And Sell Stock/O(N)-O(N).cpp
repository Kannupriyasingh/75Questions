// time complexity = O(N)
// space complexity = O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), ans = 0;
        vector<int>maxSoFar(size, -1);
        
        maxSoFar[size-1] = prices[size-1];
        
        for(int i = size-2; i >= 0; i--) {
            maxSoFar[i] = max(maxSoFar[i+1], prices[i]);
        }
        
        for(int i = 0; i < size-1; i++) {
            ans = max(ans, maxSoFar[i+1] - prices[i]);
        }
        
        return ans;
    }
};

/*
Input : [7,1,5,3,6,4]
Output : 5

maxSoFar : 7 6 6 6 6 4 

*/
