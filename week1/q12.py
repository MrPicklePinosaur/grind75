# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast =  head.next if head != None else head
        slow = head

        while (fast != None and slow != None):

            if id(fast) == id(slow):
                return True

            slow = slow.next

            fast = fast.next.next if fast.next != None else fast.next

        return False
