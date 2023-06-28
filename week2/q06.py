
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        best = -1
        count = 0

        for num in nums:
            if count <= 0:
                best = num
                count = 1
            elif num  == best:
                count += 1
            elif num != best:
                count -= 1

        return best

