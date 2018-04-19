# You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

## When building your function:

Assume your users will watch exactly two movies. Don't make your users watch the same movie twice Optimize for runtime over memory.

# Solution
We need two movies that can sum the flight length, so given a first movie duration, we need to find a second, different one that complements it.
As a brute force approach we could use a nested loop, on the outer loop we choose a first movie length and on the inner loop wee chose the complemental second movie length.
The second movie length should be equal to the flight length minus the first movie length.
The brute force approach, however, would result in an O(n^2) complexity.