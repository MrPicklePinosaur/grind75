class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        # enumerate characters in magazine
        occurs = { }
        for c in magazine:
            if c not in occurs:
                occurs[c] = 1
            else:
                occurs[c] += 1
                
        # print(occurs)

        for c in ransomNote:
            if c not in occurs or occurs[c] == 0:
                return False
            else:
                occurs[c] -= 1

        return True

## More idiomatic solution

'''
import collections

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        res =  Counter(magazine)
        res.subtract(Counter(ransomNote))
        return all(freq >= 0 for (c, freq) in res.items()) 
'''
