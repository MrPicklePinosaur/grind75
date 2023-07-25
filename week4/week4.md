
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
