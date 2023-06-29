
## Q1: First Bad Version

This question is slightly modified binary search. Once again it took me
slightly too long to complete. Definitely need more practice getting the
indices right.

## Q2: Ransom Note

Approach is to count occurrences of characters in magazine and insert into
hashmap. Then for each character in ransom note, use one occurrences in hash
map. If character is not in hashmap or it has been completely used up, ransom
note cannot be created from characters in magazine. There seems to be a cleaner
solution using the Counter type from collections. Maybe get more familiar with
python std (more specifically collections?)

## Q3: Climbing Stairs

Easy DP

## Q4: Longest Palindrome

The approach was to create a table of length 52 to hold each lower case and
upper case letter and count the occurrences. If a letter had even number of
occurrences, we can use it in the palindrome. If it was odd, we can use that
number rounded down to even number. Finally, if we have any odd numbers, we can
use one of them as the center character in an odd length palindrome.

Took a bit of time print() debugging and submitting multiple times when the
issue was that I forgot to add an offset to capital letters. Perhaps I could
benefit from reasoning through my solution and testing incrementally instead of
randomly changing things and resubmitting. This should save me a bunch of time
during an interview.

From now on, I should also time myself when doing questions to add an element
of stress?

## Q5: Reverse Linked List

Easy iterative solution the involved constructing a new linked list while
traversing through original, similar to reversing a stack by popping and then
pushing into new stack. This method is faster but has worse memory.

The second approach is to use pointer swapping and reverse the list in place.
This method is slower but has much better memory usage.

## Q6: Majority Element

Easy naive solution, count occurences of all elements and return the one that
occurs more than n/2 times. Next, to do it in linear time and constant space.
We can use Moore's Voting Algorithm, explanation [here](https://www.youtube.com/watch?v=7pnhv842keE)

## Q7: Add Binary

Simple implementation on how addition is done by hand.

## Q8: Diameter of Binary Tree

Approach is to get the best diameter of each subtree as well as the depth. At
any point we can try to make a better diameter by taking the path that goes to
the depth of left and right subtrees. We either take this new diameter or keep
a diameter of a subtree.

## Q9: Middle of the Linked List

Simple head and slow pointer implementation

## Q10: Maximum Depth of Binary Tree

Turbo easy lol

## Q11: Contains Duplicate

Went for O(n) time and O(n) space solution using a set. Can also sort and
traverse, checking if adjacent elements are the same, giving us O(1) space but
O(nlogn) time.
