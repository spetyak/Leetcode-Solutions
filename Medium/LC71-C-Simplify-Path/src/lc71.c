#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 20.58% of C submissions
 * Memory: Beats 86.06% of C submissions
 */

#define MAX_PATH_LENGTH 3000 // the maximum length the given absolute can be



/*
 * Given an absolute path for a Unix-style file system, transforms the absolute path into a simplified canonical path.
 *
 * @param path an absolute file path in the style of a Unix-based system
 * 
 * @return The simplified canonical path for the given absolute path
 */
char* simplifyPath(char* path)
{

    int outputSize = 2; // the size of the output string, initialized with 2 for the beginning '/' and the null terminator

    int stackSize = 0;      // the current size of the stack
    int stackCapacity = 10; // the current capacity of the stack

    // create a stack to keep track of directory traversals
    char** stack = malloc(stackCapacity * sizeof(char*));
    if (!stack)
    {
        printf("Unable to allocate stack!\n");
        exit(-1);
    }



    int stringLength = 0;               // the length of the current tokenized string
    char* token = strtok(path, "/");    // get the first token from the given path string

    while (token != NULL)
    {

        stringLength = strnlen(token, MAX_PATH_LENGTH);

        if (!strncmp(token, ".", MAX_PATH_LENGTH))
        {
            // do nothing
        }
        else if (!strncmp(token, "..", MAX_PATH_LENGTH))
        {

            // if .. encountered AND something exists in the stack, remove the thing before ".."
            if (stackSize)
            {
                // remove from stack
                stackSize--;
                free(stack[stackSize]);
            }

        }
        else
        {

            char* newString = malloc((stringLength+2) * sizeof(char));
            if (!newString)
            {
                printf("Unable to allocate new string!\n");
                exit(-1);
            }
            strncpy(newString, token, stringLength); // copy the token to the newly allocated string, auto null terminates last position
            newString[stringLength] = '/'; // put '/' at end of string
            newString[stringLength+1] = '\0';

            // add string to stack
            stack[stackSize] = newString;
            stackSize++;

            if (stackSize == stackCapacity) // if stack at capacity, double size
            {

                stackCapacity *= 2;
                stack = realloc(stack, stackCapacity * sizeof(char*));

            }

            outputSize += (stringLength + 1); // increase the size that the output will be by size of the directory name + '/'

        }

        

        token = strtok(NULL, "/"); // get next directory name, if there is any left

    }

    // create simplified path string
    char* simplifiedPath = malloc(outputSize * sizeof(char));
    if (!simplifiedPath)
    {
        printf("Unable to allocate output path string!\n");
        exit(-1);
    }
    simplifiedPath[0] = '/'; // set first character to root directory
    simplifiedPath[outputSize-1] = '\0';

    // if there are directories present in the stack
    if (stackSize != 0)
    {

        for (int i = 0; i < stackSize; i++)
        {

            if (i == stackSize-1) // remove the '/' from the end of the last element
            {
                stack[i][strnlen(stack[i], MAX_PATH_LENGTH) - 1] = '\0';
            }

            strncat(simplifiedPath, stack[i], MAX_PATH_LENGTH); // add current string to path

        }
        
    }

    // free stack
    for (int i = stackSize-1; i >= 0; i--)
    {
        free(stack[i]);
    }
    free(stack);

    return simplifiedPath;

}

int main() {
  
    char path[] = "/home/";
    char* simplifiedPath = simplifyPath(path);

    printf("Simplified path: \"%s\"\n", simplifiedPath);

    free(simplifiedPath);

    return 0;

}