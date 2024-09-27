"""
Author: spetyak

Runtime: Beats 56.76% of Python submissions
Memory: Beats 53.55% of Python submissions

"""

class Solution(object):

    def isValid(self, s):
        """
        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
        determines if the input string is valid.

        Args:
            s (str): the given string of open and close parentheses

        Returns:
            bool: whether the parentheses given are valid closed pairs
        """
        
        # create dictionary of open parentheses to matching closed parentheses
        parenthesesDict = {'(':')', '[':']', '{':'}'}
        
        # create empty stack to fill with open parentheses
        stack = []
        
        # for each parenthese in the given string
        for i in range(len(s)):
            
            # if the current character is an open parenthese
            if (s[i] == '(' or s[i] == '[' or s[i] == '{'):
                
                stack.append(s[i])
                
            else:
                
                # if the stack is empty but we found a close parenthese
                if len(stack) == 0:
                    
                    return False
                
                poppedOpen = stack.pop() # get the most recent open parenthese
                
                # if the current close parenthese doesn't match the last open parenthese added to the stack
                if (parenthesesDict[poppedOpen] != s[i]):
                    
                    return False
                    
        # if there are still open parentheses in the stack
        if len(stack) != 0:
            
            return False
        
        else:
        
            return True
    

def main():

    inputStr = "([[)"

    sol = Solution()

    print(f'Output: {sol.isValid(inputStr)}')

    return

if __name__ == "__main__":
    main()
