
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
