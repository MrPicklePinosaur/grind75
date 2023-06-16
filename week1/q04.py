# Best Time to Buy and Sell Stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_ind = 0
        best = 0

        for i, price in enumerate(prices):
            profit = price - prices[buy_ind]

            if profit < 0 and price < prices[buy_ind]:
                buy_ind = i

            if profit > best:
                best = profit

        return best 
