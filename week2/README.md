
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
