# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        # assume head is not None

        slow = head
        fast = head.next

        while fast != None:
            slow = slow.next
            fast = fast.next.next if fast.next != None else None

        return slow
        