
# Q1: Course Schedule

Although it was clear what the solution of this problem was, I had some issues
with implementation. Basically all that needed to be done was to detect a loop
in graph, but kept making mistakes with the recursive solution (when to visited
a node, when do we know that there is a loop, etc). Definitely should review
DFS psuedocode. Also should review implementation details on how to do DFS both
recursively and iteratively.

# Q2: Implement Trie (Prefix Tree)

Pretty straight forward. The implementation was pretty naive however, each
character was given a node. In certain cases, this can result in an excess of
nodes and longer traverses.

Node traversals are done recursively rather than iteratively, which seemed to
make it slower? In addition, a helper TrieNode struct was used. In other
languages this may not have too big of an effect but it slowed down the python
solution quite a lot I believe.

# Q03: Coin Change

Simple 1D implementation. Switched to using Cpp.

# Q04: Product of Array Except Self

First implementation involved traversing the list forward and backwards, each
time multiplying the value in the output vector by the prefix/sufix sum.

The solution didn't do very well in terms of runtime. I think it might be
possible to optimize by first scanning the vector for any zeros, as we can get
some special cases that run fast if we find zeroes.

Another solution is to compute the prefix product list and suffix product list
seperately and then multiply them together. This may result in better runtime
but has worse memory usage.

# Q05: Min Stack

Implemented using two vectors, one for maintaining the actual stack and the
other for holding the current min element. We let the last element in the min
value vector to indicate the current min value. When we push a new element to
the min stack, we just need to compare the new value and the previous min value
to decide the new min value.

Slight opttimization that we can do is only to push onto the min stack when we
have a new minimum value. Otherwise we will have a bunch of redundant values in
min stack.

# Q06: Validate Binary Search Tree

Pretty simple solution making each recurive call return if the left and right
trees are valid, as well as the min and max values for each subtree. Using this
information, we can check at any given subtree if that subtree is valid or not.

# Q07: Number of Islands

Ran with simple approach to scan map for an island and then use flood fill to
explore the entire island.

Submitted solution had pretty bad runtime and memory, could look at optimizing.

# Q08: Rotting Oranges

Pretty basic solution involving simulating the spread of the rotting oranges.
The current solution requires a good amount of copying so it's pretty bad
memory wise.

Second implemention involved multiscourse BFS. Once again, this should have
been an easy implementaiton but took really long to get details right.
Definitely, certainly review BFS, DFS and other common algorithm templates and
get fast at implementing them. What espescially takes me a long time is writing
code to explore in a grid (accessing neighouring cells etc).
