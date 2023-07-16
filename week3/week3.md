
## Q1: Insert Interval

Time take: 28 min

Approach, find the interval that overlaps with the left side of new interval,
and find the interval that overlaps with right side of new interval. Since
these intervals overlap, we should merge them. Them insert this merged interval
back in with unaffected intervals.

It once again took quite a lot of gimicking to get the indices to work
properly, need to work on this a bit. The code to find the leftmost and
rightmost intervals are also not very pythonic (or nice).

There is a much better one pass solution where we merge intervals as we go.
Solution explanation [here](https://www.youtube.com/watch?v=A8NUOmlwOlM)

## Q2: 01 Matrix

This took quite a while to implement the BFS solution. Should review search
algorithms and get much faster and writing them as well as debugging them.

There is also a DP solution that involved making a top down pass to check the
cells above and to the left, followed by a bottom up pass to chec k the cells
below and to the right.

Explanation video [here](https://www.youtube.com/watch?v=Ezj3VDOfd5I).

## Q3: K Closest Points to Origin

First implementation is to compute the distance to origin, sort based on
distance and return the first k. Runtime is O(nlogn).

Similar solution can probably be implemented using a priority heap, but we
ensure the heap contains at most K elements, which can give us a slightly
better O(nlogk) runtime.

## Q4: Longest Substring Without Repeating Characters

Pretty simple O(n) sliding window approach. Took me way too long since I kept
getting the indexing wrong.

## Q5: 3Sum

Based off of neetcode's [solution](https://www.youtube.com/watch?v=jzZsG8n2R9A)

## Q6: Binary Tree Level Order Traversal

Started off with a pretty bad solution that involved recursively merging left
and right branch solutions. Then went on to much better iterative solution that
involves processing an entire level at a time using queues.

## Q7: Clone Graph

Pretty simple DFS solution, but took very long due to combination of not
reading the question properly (return only node with id 1 etc), and also not
understanding python's memory model very well (what's a reference, when are
copies made etc).

Better explanation [neetcode](https://www.youtube.com/watch?v=mQeF6bN8hMk)

## Q8: Reverse Polish Notation

Pretty simple parsing. However the runtime and memory usage is not great. This
is perhaps due to copying the input array on each recursive call. May be better
to pass around pointers (index to where we are parsing from).
