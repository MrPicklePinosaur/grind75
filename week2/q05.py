
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

## Better performance version
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        rev = None
        cur = head
        while cur is not None:
            rev = ListNode(cur.val, rev)
            cur = cur.next

        return rev

## Better memory version
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        cur = head
        while cur is not None:
            forward = cur.next
            cur.next = prev
            prev = cur
            cur = forward

        return prev
