
"""
Author: spetyak

Runtime: Beats 89.90% of Python submissions
Memory: Beats 16.88% of Python submissions

"""

class Solution(object):

    def fullJustify(self, words, maxWidth):
        """
        Given an array of strings words and a width maxWidth, format the text such that 
        each line has exactly maxWidth characters and is fully right justified if not 
        the final line, and fully left justified if it is the final line.

        Args:
            words (List[str]): the words to fit into lines of size maxWidth
            maxWidth (int): the maximum number characters allowed in each line

        Returns:
            List[str]: justified lines containing the given words
        """
        
        lineWords = []      # the words appearing on the line currently being constructed
        output = []         # the list of fully justified lines of text
        lineSize = 0        # the total size of the line
        lineWordsSize = 0   # the size the words of the current line take up
        numSpacesInLine = 0 # the number of spaces left in the current line to be divided
        


        for word in words:

            # if the line being built is currently empty and the current word takes up the whole line
            if (lineSize == 0 and len(word) == maxWidth):

                output.append(word) # add the word as a line to the output

                # reset line tracking variables
                lineSize = 0
                lineWordsSize = 0
                lineWords.clear()
                numSpacesInLine = 0

            # if adding the current word to the current line exceeds the maximum width
            elif (lineSize + len(word) + 1 > maxWidth):

                numSpacesInLine = maxWidth - lineWordsSize # determine the number of spaces in the line

                line = "" # initialize empty line string

                # if there are more than 2 words in the current line
                if len(lineWords) > 2:

                    numSpaces = numSpacesInLine // (len(lineWords)-1)

                    # if the spaces can be divided evenly between words
                    if (numSpacesInLine % (len(lineWords)-1)) == 0: 

                        for i in range(len(lineWords)):
                            line += lineWords[i]
                            if i != len(lineWords)-1:
                                line += (" " * numSpaces)
                            
                    # the spaces between words can not be divided evenly
                    else: 

                        # determine the number of spaces that should be larger than others 
                        # to correctly justify the line
                        greaterSpacesCount = numSpacesInLine % (len(lineWords)-1) 

                        for i in range(len(lineWords)):
                            
                            # if not the last word
                            if i < len(lineWords) - 1: 
                                
                                # if more larger spaces need to be used
                                if greaterSpacesCount != 0: 
                                    
                                    line += lineWords[i] + (" " * (numSpaces+1))
                                    greaterSpacesCount -= 1
                                    
                                # use the smaller size of spaces
                                else: 
                                    
                                    line += lineWords[i] + (" " * numSpaces)
                            
                            # add the final word to the line
                            else:
                                
                                line += lineWords[i]

                # if there are JUST 2 words in the current line
                elif len(lineWords) == 2: 

                    line = lineWords[0] + (" " * (numSpacesInLine)) + lineWords[1]

                # if there is a single word in the current line
                else: 

                    line = lineWords[0] + (" " * numSpacesInLine)

                output.append(line) # add the fully justified line to the output list

                # reset line tracking variables and add current word to new line
                lineSize = len(word)
                lineWordsSize = len(word)
                lineWords.clear()
                lineWords.append(word)
                numSpacesInLine = 0
                
            else:

                if lineSize == 0:
                    
                    lineSize += len(word)
                    
                else:
                    
                    lineSize += len(word) + 1
                    
                lineWordsSize += len(word)
                lineWords.append(word)



        # if there is still a final line to add
        # this time, LEFT JUSTIFY
        if (len(lineWords) != 0):

            numSpacesInLine = maxWidth - lineWordsSize # determine the number of spaces in the line 

            line = "" # initialize empty line string

            # if there are more than 2 words in the current line
            if len(lineWords) > 2:

                for i in range(len(lineWords)):
                    
                    # if not the last word
                    if i != len(lineWords) - 1: 
                        
                        line += lineWords[i] + " " # add word to line followed by space
                        
                        # if not all spaces have been used
                        if numSpacesInLine > 0:
                            
                            numSpacesInLine -= 1 # decrement counter
                    
                    # if last word
                    else: 
                        
                        line += lineWords[i] + (" " * numSpacesInLine) # add final word and remaining spaces

            # if there are JUST 2 words in the current line
            elif len(lineWords) == 2: 

                line = lineWords[0] + " " + lineWords[1] + (" " * (numSpacesInLine-1))

            # if there is a single word in the current line
            else: 

                line = lineWords[0] + (" " * numSpacesInLine)

            output.append(line) # add final line to output list



        return output

def main():

    sol = Solution()
    
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    
    sol.fullJustify(words, maxWidth)

    return

if __name__ == "__main__":
    main()