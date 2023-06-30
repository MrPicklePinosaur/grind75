class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        T = set([])
        for num in nums:
            if num in T:
                return True
            T.add(num)

        return False
