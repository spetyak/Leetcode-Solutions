"""
Author: spetyak

Runtime: Beats 80.80% of Python submissions
Memory: Beats 91.31% of Python submissions

"""

class Solution(object):

    def intToRoman(self, num):
        """
        Converts an integer to a Roman numeral

        Args:
            num (int): the integer value that is being converted to a Roman numeral

        Returns:
            str: the Roman numeral representation of the given integer
        """

        # dictionary containing Roman numerals and their associated integer value
        romanNumeralsDict = {
            'I' : 1,
            'IV' : 4,
            'V' : 5,
            'IX' : 9,
            'X' : 10,
            'XL' : 40,
            'L' : 50,
            'XC' : 90,
            'C' : 100,
            'CD' : 400,
            'D' : 500,
            'CM' : 900,
            'M' : 1000
        }

        output = "" # the Roman numeral to be returned

        # consider larger numerals first and work to smaller numerals
        for item in list(romanNumeralsDict.items())[::-1]:

            currentNumeral = item[0]
            currentVal = item[1]

            # loop until the current numeral being considered no longer fits in the remaining value
            while num >= currentVal:

                num -= currentVal           # remove the current numeral value from the input number
                output += currentNumeral    # add the associated numeral to the output string

        return output


def main():

    inputNum = 1994
    sol = Solution()

    print(f'Output: {sol.intToRoman(inputNum)}')

    return

if __name__ == "__main__":
    main()