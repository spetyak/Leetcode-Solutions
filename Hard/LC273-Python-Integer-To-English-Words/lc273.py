
"""
Author: spetyak

Runtime: Beats --.--% of Python submissions
Memory: Beats --.--% of Python submissions

"""

class Solution(object):

    def numberToWords(self, num: int) -> str:
        """
        Convert a non-negative integer num to its English words representation.

        Args:
            num (int): the integer number to be converted to English words

        Returns:
            str: the English word representation of the given integer
        """

        if num == 0:

            return "Zero"

        ones = {1:"One",
                2:"Two",
                3:"Three",
                4:"Four",
                5:"Five",
                6:"Six",
                7:"Seven",
                8:"Eight",
                9:"Nine"}

        teens = {11:"Eleven",
                12:"Twelve",
                13:"Thirteen",
                14:"Fourteen",
                15:"Fifteen",
                16:"Sixteen",
                17:"Seventeen",
                18:"Eighteen",
                19:"Nineteen"}

        tens = {10:"Ten",
                20:"Twenty",
                30:"Thirty",
                40:"Forty",
                50:"Fifty",
                60:"Sixty",
                70:"Seventy",
                80:"Eighty",
                90:"Ninety"}

        group = ["", "Thousand", "Million", "Billion"]

        output = ""
        groupIndex = 0

        while num != 0:

            current = num % 1000
            num = num // 1000

            # add group identifier (thousands, millions, etc.) for current group
            if current != 0:

                output = group[groupIndex] + " " + output

            # ten and ones places are special case numbers (teens)
            if current % 100 > 10 and current % 100 < 20:

                output = (teens[current % 100]) + " " + output

            else:

                # deal with ones place (if anything)
                if current % 10 > 0:

                    output = (ones[current % 10]) + " " + output

                # deal with tens place (if anything)
                if ((current // 10) % 10) * 10 > 0:

                    output = (tens[((current // 10) % 10) * 10]) + " " + output

            # deal with hundreds place (if anything)
            if current // 100 > 0:

                output = (ones[current // 100]) + " Hundred " + output



            groupIndex += 1 # increment to next grouping



        return output.strip()
                
                
    
def main():

    sol = Solution()
    
    num = 1234567

    print(f"Output: \"{sol.numberToWords(num)}\"")

    return

if __name__ == "__main__":
    main()