"""
Author: spetyak

Runtime: Beats 22.07% of Python submissions
Memory: Beats 28.61% of Python submissions

"""

class Stack(object):

    def __init__(self):

        self.storage = []

        return
    
    def push(self, val):

        self.storage.append(val)

        return
    
    def pop(self):
        
        return self.storage.pop();
    
    def size(self):
        
        return len(self.storage)

class Solution(object):

    def longestValidParentheses(self, s):

        stack = Stack() # create a stack used to track parenthetical openings
        legalPars = [0] * len(s) # create an array used to track positions of legal parentheses

        for i in range(len(s)):

            if s[i] == '(':

                stack.push(i) # put position of opening on stack

            else: # if s[i] == ')'

                if stack.size() != 0: # if we have an unused open parentheses we've seen

                    j = stack.pop() # get the position of the open parentheses

                    # mark the location of the legal pair in the array
                    legalPars[i] = 1
                    legalPars[j] = 1

        currentMax = 0 # the current largest parentheses found

        for i in range(1, len(s)):

            if legalPars[i] == 1: # if this is part of a legal parentheses pair

                legalPars[i] += legalPars[i-1] # sum with previous neighbor to get current length

                if legalPars[i] > currentMax:

                    currentMax = legalPars[i]

        return currentMax
    

    
def main():
    s = ")(())())"
    sol = Solution()
    longestPar = sol.longestValidParentheses(s)
    print(f'Longest valid parentheses: {longestPar}')

if __name__ == "__main__":
    main()