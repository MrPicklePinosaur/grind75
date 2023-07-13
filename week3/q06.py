
# Pretty bad merge solution
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        l = self.levelOrder(root.left)
        r = self.levelOrder(root.right)
        merge = [(l[i] if i < len(l) else [])+(r[i] if i < len(r) else []) for i in range(max(len(l), len(r)))]

        # merge left and right
        return [[root.val]] + merge

# Much better queue based solution
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if root is None:
            return []

        q = deque([])
        q.append(root)

        res = []
        while len(q) > 0:
            cur_level = []
            for _ in range(len(q)):
                cur_node = q.popleft()
                cur_level.append(cur_node.val)
                if cur_node.left:
                    q.append(cur_node.left)
                if cur_node.right:
                    q.append(cur_node.right)
            if len(cur_level) > 0:
                res.append(cur_level)

        return res
