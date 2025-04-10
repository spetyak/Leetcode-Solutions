
"""
Author: spetyak

Runtime: Beats 41.56% of Python submissions
Memory: Beats 22.96% of Python submissions

"""

class Solution:

    def minCut(self, s: str) -> int:
        """
        Description

        Args:
            s (str): _description_

        Returns:
            int: _description_
        """

        g = [[True for i in range(len(s))] for j in range(len(s))]
                
        for i in range(len(s)-1, -1, -1):

            for j in range(i+1,len(s)):

                g[i][j] = s[i] == s[j] and g[i+1][j-1]

        # print(g)

        cuts = list(range(len(s)))

        # print(cuts)

        for i in range(1, len(s)):

            for j in range(i+1):

                if g[j][i]:

                    # print(f"i: {i}, j: {j}")

                    cuts[i] = min(cuts[i], 0 if j == 0 else 1 + cuts[j-1])

        # print(cuts)

        return cuts[-1]

    
def main():

    sol = Solution()

    s = "aabacabac"

    output = sol.minCut(s)
    
    print(f"Output: {output}")

    return

if __name__ == "__main__":
    main()