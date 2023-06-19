
# Week 1 Writeup


## Q7: Valid Anagram

Originally my solution involved sorting both strings and then comparing them,
which runs O(nlogn). A better solution (linear) turned out to be since we have
a limited character set, we can just use a 26 element array (one for each
lowercase letter) and count the frequencies of each character.

I think the test cases on leetcode weren't big enough though since the
performance after using the linear solution seemed to be worse.

## Q8: Binary Search

This question actually took an embarrassingly long amount of time to complete.
I noticed this a lot in some of my interviews too, but it seems that I have a
lot of issues getting indices right. There's always some off by one issues.
Should consider doing more questions like these to stop making simple mistakes.

## Q9: Flood Fill

The majority of the time taken to do this question had to do with figuring out
the API for set in python. It may be worth familiarizing myself with common
data structures in python like heap, queue, set, map etc.

Furthermore, the syntax for list comprehension gets a bit more ugly once we
start adding more conditions, can try to take a look at some more functional
programming like functions like map and filter in python.

## 10: Lowest Common Ancestor of a Binary Search Tree

Easy

## 11: Balanced Binary Tree

Recursively explore branches of tree and compare height of left and right
subtrees. Return type is a tuple `(bool, int)` where the `bool` represents if
the tree was balanced and the right for the height of the tree. The reason we
also return a bool is that if a single subtree is unbalanced we can return
right away. This allows us to short circuit a lot of the checks we need to do.

## 12: Linked List Cycle

My original implementation keeps track of the visited nodes by using their
memory address. We know that we have a loop if we return to a node that we have
visited. However, this uses linear memory. For the constant memory solution, we
can use the two pointer algorithm, using a pointer that traverses the linked
last one one at a time and  one that traverses two nodes at a time.

## 13: Implement Queue Using Stacks

Implementation is amortized O(n). Make use of two stacks, one where the top
represents the front of the queue and one where the top represents the back.
When we push to queue, we push to the back stack. When we pop from queue, we
pop from front stack. When the front stack is empty, we then shift all items
from back stack to front stack.

