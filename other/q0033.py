
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        # nums = [1,3]
        # target = 1

        # Binary search to the pivot
        pivot = None
        if len(nums) == 0:
            return -1
        elif len(nums) == 1:
            pivot = 0
        elif len(nums) == 2:
            pivot = 0 if nums[0] < nums[1] else 1
        else:
            l, r = 0, len(nums)-1
            m = None
            while r-l > 1:
                # This chunk is not rotated
                m = (r + l) // 2
    
                if nums[m] > nums[r]:
                    l = m
                else:
                    r = m

            pivot = l if nums[l] < nums[r] else r

        # Unpivot array
        nums = nums[pivot:] + nums[:pivot]

        #print("pivot", pivot)
        #print("nums", nums)

        # Binary search again
        l, r = 0, len(nums)-1
        m = -1
        while l <= r:
            m = (r + l) // 2
            #print(l, r, m)

            if nums[m] == target:
                # return shifted index
                return (m+pivot)%len(nums)
            elif nums[m] < target:
                l = m+1
            else:
                r = m-1

        return -1

