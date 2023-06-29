
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        a = a.rjust(n, "0")
        b = b.rjust(n, "0")

        res = ""
        carry = 0
        for i in range(n):
            add = int(a[n-1-i]) + int(b[n-1-i]) + carry
            carry = add // 2
            res = str(add % 2) + res 

        if carry > 0:
            res = str(carry) + res
            
        return res
