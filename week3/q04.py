class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        T = {}

        length = 0
        start = 0
        for i, ch in enumerate(s):

            if ch in T:
                start = max(start, T[ch]+1)

            # update last occurence of character
            T[ch] = i
            length = max(length, i-start+1)
            #print(length, start, T)        

        return length
