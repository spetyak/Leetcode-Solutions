"""
Author: spetyak

Runtime: Beats 40.15% of Python submissions
Memory: Beats 94.39% of Python submissions

"""

class Solution(object):

    def convertCharToDigit(self, char):
        """
        Converts a given integer character to its integer equivalent.

        Args:
            char (char): the character to be converted

        Returns:
            (int): the digit associated with the given character
        """

        match char:

            case '0':
                return 0
            case '1':
                return 1
            case '2':
                return 2
            case '3':
                return 3
            case '4':
                return 4
            case '5':
                return 5
            case '6':
                return 6
            case '7':
                return 7
            case '8':
                return 8
            case '9':
                return 9
            case _:
                print("Something went wrong!")
                return -1

    def convertDigitToChar(self, digit):
        """
        Converts a given digit integer to its character equivalent.

        Args:
            digit (int): the digit to be converted

        Returns:
            (char): the character associated with the given digit
        """

        match digit:

            case 0:
                return '0'
            case 1:
                return '1'
            case 2:
                return '2'
            case 3:
                return '3'
            case 4:
                return '4'
            case 5:
                return '5'
            case 6:
                return '6'
            case 7:
                return '7'
            case 8:
                return '8'
            case 9:
                return '9'
            case _:
                print("Something went wrong!")
                return 'X'

    def multiply(self, num1, num2):
        """
        Multiplies two strings representing integers without the use of built-in conversion functions.

        Args:
            num1 (str): the first number given
            num2 (str): the second number given

        Returns:
            (str): the product of the two number strings passed in
        """
        
        converted1 = 0 # the holding integer for the first number
        converted2 = 0 # the holding integer for the second number
        result = 0 # the integer result of multiplying the first and second number
        outputStringStack = [] # the stack of digits that make up the result 
        outputString = "" # the output string to be returned

        place = 1
        for digitChar in reversed(num1): # work backwards through the first numbers digits
            digit = self.convertCharToDigit(digitChar) # convert the character to a digit
            converted1 += (digit * place) # multiply the digit by its place (ones, tens, etc.)
            place *= 10 # update the place integer

        place = 1
        for digitChar in reversed(num2): # work backwards through the second numbers digits
            digit = self.convertCharToDigit(digitChar) # convert the character to a digit
            converted2 += (digit * place) # multiply the digit by its place (ones, tens, etc.)
            place *= 10 # update the place integer

        result = converted1 * converted2 # calculate the integer product of the two numbers

        while (result > 0): # while the remaining number is greater than 0...

            outputStringStack.append(self.convertDigitToChar(result % 10)) # put the ones digit as a character on the output string stack

            result = result // 10 # cut off the current ones place by using integer division

        if (len(outputStringStack) == 0): # if the stack is empty...

            outputString += "0"

        else:

            while (len(outputStringStack) != 0): # while there are more digit characters on the stack

                outputString += outputStringStack.pop()

   

        return outputString

def main():

    num1 = "2"
    num2 = "3"

    sol = Solution()

    print(f'Output: {sol.multiply(num1, num2)}')

    return

if __name__ == "__main__":
    main()
