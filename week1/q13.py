class MyQueue:
    # top of stack represents front
    fstack = []
    # top of stack represents back
    bstack = []


    def __init__(self):
        self.fstack = []
        self.bstack = []

    def push(self, x: int) -> None:
        self.bstack.append(x)

    # if fstack is empty shift all of back to front
    def _maybe_shift(self):
        if len(self.fstack) == 0:
            for i in range(len(self.bstack)):
                self.fstack.append(self.bstack.pop())

    def pop(self) -> int:
        self._maybe_shift()
        return self.fstack.pop()

    def peek(self) -> int:
        self._maybe_shift()
        return self.fstack[-1]

    def empty(self) -> bool:
        return (len(self.fstack)+ len(self.bstack) == 0)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
