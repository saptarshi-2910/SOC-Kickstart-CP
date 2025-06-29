class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN_PRIZE=INT_MAX;
        int maxprofit=0;

        for (int i=0;i<prices.size();i++){
            int price=prices[i];

            if (price < MIN_PRIZE){
                MIN_PRIZE = price;
            }
            else if(price > MIN_PRIZE + maxprofit){
            maxprofit = price-MIN_PRIZE;
            }
        }
    return maxprofit;

    }
};