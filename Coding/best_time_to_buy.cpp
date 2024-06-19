#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = INT_MAX;
        int result = 0;
        int t = 0;
        int n = prices.size();
        int minElement = *std::min_element(prices.begin(), prices.end());

        for (int i = 0; i < n - 1; i++) {
            if (prices[i] < prices[i + 1]){
                result=result+1;
                break;
            }
                
        }

        if (result==0){
            return 0;
        }
            
        else {
            for (int i = 0; i < n; i++) {
                if (prices[i] == minElement)
                    t = i;
            }
        }

        std::sort(prices.begin() + t, prices.end());
        return (prices[n - 1] - minElement);
    }
};