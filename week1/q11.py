# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        (balanced, height) = self._isBalanced(root)
        return balanced

    def _isBalanced(self, root: Optional[TreeNode]) -> (bool, int):
        if root == None:
            return (True, 0)

        (l_bal, l_h) = self._isBalanced(root.left)
        (r_bal, r_h) = self._isBalanced(root.right)

        bal = l_bal and r_bal and abs(l_h - r_h) <= 1
        h = 1 + max(l_h, r_h)
        return (bal, h)
