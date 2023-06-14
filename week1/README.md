
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

