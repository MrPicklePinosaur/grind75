
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        (diam, dep) = self.depth_helper(root)
        return diam
    
    # return diameter and also the depth
    def depth_helper(self, root: Optional[TreeNode]) -> (int, int):
        if root == None:
            return (0, 0)
        
        (l_diam, l_dep) = self.depth_helper(root.left)
        (r_diam, r_dep) = self.depth_helper(root.right)

        return (max(l_dep+r_dep, l_diam, r_diam), 1+ max(l_dep, r_dep))
