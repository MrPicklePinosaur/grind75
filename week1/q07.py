# Valid Anagram

class Solution:

    def count_freq(self, s: str) -> [int]:
        s_freq = [0 for i in range(26)]
        for ch in s:
            s_freq[ord(ch)-ord('a')] += 1
        return s_freq

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        return self.count_freq(s) == self.count_freq(t)
