class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        (res, leftover) = self.parse_and_eval(tokens)
        #print(self.parse_and_eval(['+', '2', '1']))

        return res

    def parse_and_eval(self, tokens: List[str]) -> (int, List[str]):
        if len(tokens) == 0:
            # we are done with parsing
            return (None, [])

        t = tokens[-1]
        if t.strip('-').isnumeric():
            #print("found number ", int(t))
            return (int(t), tokens[:-1])

        # parse binary op
        (right, leftover) = self.parse_and_eval(tokens[:-1])
        (left, leftover) = self.parse_and_eval(leftover)
        #print("evaluate", t, left, right)

        if t == '+':
           res = left + right 
        elif t == '-':
            res = left - right
        elif t == '*':
            res = left * right
        elif t == '/':
            # this is a strange solution lol
            if (left >= 0 and right >= 0) or (left <= 0) and (right <= 0):
                res = left // right
            else:
                res = -1 * (abs(left) // abs(right))
        else:
            print('undefined operator ', t)

        return (res, leftover)

        
