
"""
Author: spetyak

Runtime: Beats 71.74% of Python submissions
Memory: Beats 20.58% of Python submissions

"""

class Solution(object):

    def minDistance(self, word1, word2):
        """
        Given two strings word1 and word2, returns the minimum number of operations required 
        to convert word1 to word2. Three operations are permitted to convert word1: 
        inserting a character, deleting a character, or replacing a character

        Args:
            word1 (str): the word to transform
            word2 (str): the target word to transform the other word into

        Returns:
            int: the minimum number of operations required to convert word1 to word2
        """
        
        # create dynamic programming table
        # initialize costs of deleting along table right and bottom boundaries
        # work from bottom right corner of table to top left
        dpTable = [[0 for i in range(len(word1)+1)] for j in range(len(word2)+1)]
        
        for i in range(len(word1), -1, -1):
            
            dpTable[len(word2)][len(word1) - i] = i
            
        for i in range(len(word2), -1, -1):
            
            dpTable[len(word2) - i][len(word1)] = i
            
        
        
        # work from final character of each string (bottom right corner of dpTable)
        for i in range(len(word2)-1, -1, -1):
            
            for j in range(len(word1)-1, -1, -1):
                
                if (word2[i] == word1[j]): # if the characters at the current position match
                    
                    dpTable[i][j] = dpTable[i+1][j+1] # no work needs to be done
                    
                else: # characters don't match, determine minimum costing option of deleting, inserting, or replacing
                    
                    dpTable[i][j] = min(dpTable[i][j+1], dpTable[i+1][j], dpTable[i+1][j+1]) + 1
        
        
         
        return dpTable[0][0] # return minimum cost to change word1 to word2

def main():

    sol = Solution()
    
    word1 = "horse"
    word2 = "ros"
    
    sol.minDistance(word1, word2)
    
    word1 = "intention"
    word2 = "execution"
    
    sol.minDistance(word1, word2)
    
    

    return

if __name__ == "__main__":
    main()