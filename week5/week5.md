
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
