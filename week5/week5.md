
# Q01: Search in Rotated Sorted Array

Solved using modified binary search that uses two cases to determine the search
space. Given a pivoted array, we can determine easily if we are in the left or
right subarray of the pivoted array.

[details](https://www.youtube.com/watch?v=U8XENwh8Oy8)

# Q02: Combination Sum

Simple bottom up 1D DP solution. We can guarentee that combinations are unique
by forcing each of the combaintion to be strictly increasing.

We can probably improve this solution by making the DP top down instead.

[this solution](https://www.youtube.com/watch?v=GBKI9VSKdGg) solves it using
backtracking and a decision tree.

# Q03: Permutations

Pretty simple implementaiton that involves swapping elements while slowly
growing the part of the array that stays constant.

# Q04: Merge Intervals

Very simple implementation, had some issues with cpp sort function not behaving
as expected however.

# Q05: Lowest Common Ancestor of a Binary Tree

Misread the question and thought it was a binary search tree, not a regular
binary tree. Make sure to read problem properly next time.

The proper implementation was quite straight forward but some parts of cpp made
it a bit clunky, especially with returning multiple values from functions.
Should see how this can be done in a cleaner way.

# Q06: Time Based Key-Value Store

Once again didn't read input spec and missed that the set operations will use
strictly increasing timestamps, which once again wasted a bunch of time.

In all, this once again took embarassing long to get the binary search correct.
Should definitely do a bunch of practice involoving different variations of
binary search, taking into consideration the exit condition, how to reassign
left and right pointers etc.
