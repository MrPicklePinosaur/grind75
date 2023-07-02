
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        N = len(intervals)
        out = []

        for i in range(N):
            [n_l, n_r] = newInterval
            [i_l, i_r] = intervals[i]
            if n_r < i_l:
                return out + [newInterval] + intervals[i:]
            elif n_l <= i_r:
                newInterval = [min(n_l, i_l), max(n_r, i_r)]
            else:
                out.append(intervals[i])

        out.append(newInterval)
        return out





