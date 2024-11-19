#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 83.35% of C submissions
 */



/*
 * Performs simple bit addition, flagging carry bits as needed.
 *
 * @param a the first bit to be summed
 * @param b the second bit to be summed
 * @param carry a flag to account for carry bits as a result of addition overflow
 * 
 * @return The same-significance result of the additions (ie. '1'+'1' will result in '0', not '10')
 */
char addBitChars(char a, char b, int* carry) {

    if (a == b) // the numbers are the same
    {

        if (a == '1') // both are 1's
        {

            if (*carry == 1)
            {
                return '1';
            }
            else
            {
                *carry = 1;
                return '0';
            }
            
        }
        else // both are 0's
        {
            if (*carry == 1)
            {
                *carry = 0;
                return '1';
            }
            else
            {
                return '0';
            }

        }

    }
    else // the numbers are different
    {
        
        if (*carry == 1)
        {
            return '0';
        }
        else
        {
            *carry = 0;
            return '1';
        }
       
    }

}

/*
 * Given two strings a and b representing binary numbers, returns their sum as a binary string.
 *
 * @param a the first string to be summed
 * @param b the second string to be summed
 * 
 * @return The sum of the given binary numbers represented as a string
 */
char* addBinary(char* a, char* b) {

    int numBitsA = 0; // the number of bits string a represents
    int numBitsB = 0; // the number of bits string b represents
    
    // find the number of bits in the binary string a (the string length)
    int i = 0;
    while (a[i])
    {
        i++;
    }
    numBitsA = i;

    // find the number of bits in the binary string b (the string length)
    i = 0;
    while(b[i])
    {
        i++;
    }
    numBitsB = i;

    int maxLength = (numBitsA > numBitsB) ? numBitsA : numBitsB; // the maximum length of the two strings
    int outputSize = maxLength + 2; // the output size will be at most 2 greater than the longer string to account for a carry bit and null terminator

    // allocate output string
    char* outputStr = malloc(outputSize * sizeof(char));
    if (!outputStr)
    {
        printf("Unable to allocate output string!\n");
        exit(-1);
    }

    // initialize string to all null terminators
    for (int i = 0; i < outputSize; i++)
    {
        outputStr[i] = '\0';
    }


    i = 1;          // index pointer used to point to end of given strings and populate output string
    int carry = 0;  // flag used to determine the presence of a carry bit in the addition

    while (i < numBitsA+1 && i < numBitsB+1) // sum bits of the same significance together
    {

        outputStr[i] = addBitChars(a[numBitsA - i], b[numBitsB - i], &carry);

        i++;

    }

    while (i < numBitsA+1) // binary string a did not have all its bits added to the sum
    {

        outputStr[i] = addBitChars(a[numBitsA - i], '0', &carry);

        i++;

    }

    while (i < numBitsB+1) // binary string b did not have all its bits added to the sum
    {

        outputStr[i] = addBitChars('0', b[numBitsB - i], &carry);

        i++;

    }

    // if there is a leftover carry bit after all addition of pre-existing bits has finished
    if (carry == 1)
    {
        outputStr[i] = '1';
    }

    // reverse string
    char temp = '0';
    for (int i = 0; i < outputSize/2; i++)
    {
        temp = outputStr[i];
        outputStr[i] = outputStr[outputSize-(i+1)];
        outputStr[outputSize-(i+1)] = temp;
    }

    // if null in first position, shift left
    if (outputStr[0] == '\0')
    {
        for (int i = 0; i < outputSize-1; i++)
        {
            outputStr[i] = outputStr[i+1];
        }
        outputStr[outputSize - 1] = '\0';
    }

    

    return outputStr;

}

int main() {
  
    char* a = "1111";
    char* b = "1111";

    char* output = addBinary(a, b);

    printf("Output: %s\n", output);

    if (!output)
    {
        free(output);
    }

    return 0;

}