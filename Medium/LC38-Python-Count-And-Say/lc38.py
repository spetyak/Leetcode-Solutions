"""
Author: spetyak

Runtime: Beats 56.91% of Python submissions
Memory: Beats 47.78% of Python submissions

"""

class Solution(object):

    def say(self, string):

        currentChar = ""
        currentCharCount = -1
        outputStr = ""

        for char in string:

            if currentChar == "": # if this char is the first character we've seen in the string

                currentChar = char
                currentCharCount = 1

            elif char != currentChar: # if this char doesn't match the last character we've seen

                outputStr = outputStr + str(currentCharCount) + currentChar # update output string
                currentChar = char # reset
                currentCharCount = 1 # reset

            else: # if this character matches the last character we saw

                currentCharCount += 1

        outputStr = outputStr + str(currentCharCount) + currentChar # final update

        return outputStr

    def countAndSay(self, n):

        if n == 1: # base case

            return "1"

        else:
            
            string = self.countAndSay(n-1)

            return self.say(string)

def main():

    inputNum = 5

    sol = Solution()

    print(f'Output: {sol.countAndSay(inputNum)}')

    return

if __name__ == "__main__":
    main()
