## Input Format

The first line contains the number of test cases, .  test cases follow.

Each test case consists of a single line containing two space-separated strings  (the patient DNA) and  (the virus DNA).

## Constrains

-   1<=t<=10
-   p and v contain at most 10^5 characters each
-   all characters in p and v are lowercase english letters.

# Solution approach
The first solution that comes to my mind is tho compare every substring of the string p with length equals to the v string and output those which differ with v in at most one position. This runs in O(|p||v|) time.

