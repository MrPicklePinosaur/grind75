class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        best = -1000000
        cur = 0
        for num in nums:
            cur += num

            if cur > best :
                best = cur

            if cur < 0:
                cur = 0

        return best
            
            



