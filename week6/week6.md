
# Q01: Word Break

Pretty simple DP

# Q02: Partition Equal Subset Sum

Solved by reducing this problem into subset sum. We first count the total sum
of the input vector and set our target to half of the sum. We then run subset
sum on this target.

To note: take the input restrictions into consideration when designing the
algorithm too. For example, if the target could have been a very large number,
perhaps the DP solution wouldn't have been as good as a simple decision tree.

# Q03: String to Integer (atoi)

Passed the tests easily but I feel like the code wasn't the most clean,
especially the clamping part. Could optionally review cpp's stream functions
and best practices for parsing.

# Q04: Spiral Matrix

Quite easy conceptually but took a tiny bit to think of the best way to
traverse the matrix.

# Q05: Subsets

Quite simple solution, I beleive there could be a decent amount of
optimizations when reducing copies however. Can also use an alternate decision
tree solution.

# Q06: Binary Tree Right Side View

Pretty slow solution that involves merging solution from left and right
subtrees. Should implement BFS solution.

