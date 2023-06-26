class Solution:
    def longestPalindrome(self, s: str) -> int:
        T = [0 for i in range(52)]

        for ch in s:
            if ch.islower():
                T[ord(ch)-ord('a')] += 1
            elif ch.isupper():
                T[ord(ch)-ord('A')+26] += 1

        # print(T)

        length = 0
        found_odd = False
        for count in T:
            if count % 2 == 0:
                length += count
                # print('adding even', count, length)
            else:
                length += (count // 2) * 2
                # print('adding odd', count, length)
                found_odd = True

        if found_odd:
            length += 1

        return length
