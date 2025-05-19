
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 91.88% of Python submissions

"""

outputList = [] # the list of all possible sentences made from s using valid dictionary words

class Solution:

    def helper(self, s, wordDict, currentSentence):
        """
        Recursively builds sentences from the given string s using words in wordDict.

        Args:
            s (str): the given string
            wordDict (List[str]): the dictionary of words that can be used in a sentence
            currentSentence (str): the current sentence being constructed
        """

        global outputList

        if len(s) == 0: # if no letters remain in s, all have been used in a sentence

            currentSentence = currentSentence.strip()   # strip trailing whitespace
            outputList.append(currentSentence)          # add to the list of valid sentences

        buildStr = "" # initialize an empty string that will be used to build words from s

        for i in range(len(s)):

            buildStr += s[i] # add the current letter to the build string

            if buildStr in wordDict: # if the build string is a word, add it to the sentence

                self.helper(s[i+1:len(s)], wordDict, currentSentence + buildStr + " ")



    def wordBreak(self, s, wordDict):
        """
        Given a string s and a dictionary of strings wordDict, 
        returns all possible sentences made by placing spaces between valid dictionary words in s.

        Args:
            s (str): the given string
            wordDict (List[str]): the dictionary of words that can be used in a sentence

        Returns:
            List[str]: A list of all possible sentences.
        """

        global outputList

        outputList = [] # initialize outputlist to empty list

        self.helper(s, wordDict, "") # make helper do all the work lol

        return outputList
                
                
    
def main():

    sol = Solution()

    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    
    output = sol.wordBreak(s, wordDict)

    print("Output sentences:")
    for sentence in output:
        print(f"\t {sentence}")

    return

if __name__ == "__main__":
    main()