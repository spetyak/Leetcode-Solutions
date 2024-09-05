"""
Author: spetyak

Runtime: Beats 94.71% of Python submissions
Memory: Beats 70.93% of Python submissions

"""

class Solution(object):


    def myAtoi(self, s):
        """
        Converts a given string to an integer.

        Args:
            s (str): the input string

        Returns:
            num (int): the converted integer
        """

        

        s = s.strip()   # strip leading white space

        num = 0     # the converted number
        sign = 1    # number assumed to be positive, may be negative if minus sign leading number



        # loop through characters in string
        for i in range(len(s)):

            currentChar = s[i]

            if i == 0: 

                if currentChar == '-':      # the number will be negative

                    sign = -1
                    continue

                elif currentChar == '+':    # the number will be positive

                    sign = 1
                    continue

            if ord(currentChar) >= 48 and ord(currentChar) <= 57: # its a number

                num *= 10                               # make space for new digit
                num += (ord(currentChar) - 48) * sign   # add new digit to integer

                if num >= 2147483647:       # if current number is greater than 32-bit int max, round to int max

                    return 2147483647

                elif num <= -2147483648:    # if current number is greater than 32-bit int min, round to int min

                    return -2147483648

            else:

                break

        return num

def main():

    inputStr = '+0 123'

    sol = Solution()

    print(f'Output: {sol.myAtoi(inputStr)}')

    return

if __name__ == "__main__":
    main()