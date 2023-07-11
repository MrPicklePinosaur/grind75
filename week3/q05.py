
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)

        res = []

        # print(two_sum([-3,-3,1,2,3,4], -3, 1))
        
        left = 0
        prev = None
        while left < len(nums):
            cur = nums[left]

            # run two sum 2 on rest of list
            new_res = two_sum(nums,  cur, left+1)
            res += new_res
    
            # increment while skipping duplicate values
            left  = skip_while(nums, left)

        return res

def two_sum(nums, target, ind):
    res = []
    target = -target

    l, r = ind, len(nums) - 1

    while l < r:
        cur_sum = nums[l]+nums[r]
        #print('cur_sum', cur_sum)

        if cur_sum == target:
            res.append([-target, nums[l], nums[r]])
            r -= 1
            l  = skip_while(nums, l)
        elif cur_sum > target:
            r -= 1
        elif cur_sum < target:
            l  = skip_while(nums, l)

    return res

def skip_while(nums, ind):
    new_ind = ind+1
    cur = nums[ind]
    while  new_ind < len(nums) and nums[new_ind] == cur:
        new_ind+=1
    return new_ind
