
"""
Author: spetyak

Runtime: Beats 41.56% of Python submissions
Memory: Beats 22.96% of Python submissions

"""

class Solution:

    def minCut(self, s: str) -> int:
        """
        Given a string s, returns the minimum numbers of cuts needed for a palindrome
        partitioning of s.

        Args:
            s (str): the given string to be partitioned into palindromes

        Returns:
            int: The minimum number of cuts needed for a palindrome partitioning of the given string.
        """

        # Used algorithm from this explanation: https://algo.monster/liteproblems/456
        # Not gonna lie the websites explanation was kinda trash so I have no clue how it works

        g = [[True for i in range(len(s))] for j in range(len(s))]
                
        for i in range(len(s)-1, -1, -1):

            for j in range(i+1,len(s)):

                g[i][j] = s[i] == s[j] and g[i+1][j-1]

        cuts = list(range(len(s)))

        for i in range(1, len(s)):

            for j in range(i+1):

                if g[j][i]:

                    cuts[i] = min(cuts[i], 0 if j == 0 else 1 + cuts[j-1])

        return cuts[-1]

    
def main():

    sol = Solution()

    s = "aabacabac"

    output = sol.minCut(s)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()