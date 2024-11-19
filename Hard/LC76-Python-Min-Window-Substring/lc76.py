
"""
Author: spetyak

Runtime: Beats 88.26% of Python submissions
Memory: Beats 35.70% of Python submissions

"""

class Solution(object):

    def minWindow(self, s, t):
        """
        Given two strings s and t of lengths m and n respectively, 
        return the minimum window substring of s such that every character in t 
        (including duplicates) is included in the window. 
        If there is no such substring, return the empty string "".

        Args:
            s (str): the string to be searched through for a valid substring
            t (str): the string of required letters

        Returns:
            str: the smallest substring of s that contains all letters from t
        """
        
        # edge case of empty requirement string
        if t == "":
            return ""
        
        countT = {} # map of characters required for substring to be valid
        window = {} # map of the characters in the current consideration window
        
        # update letter counts from the given t string
        for c in t:
            countT[c] = countT.get(c, 0) + 1 
            
        have = 0            # the number of criteria met by the current window
        need = len(countT)  # the number of criteria required by the given requirement string
        
        minSub = [-1, -1]               # the boundaries of the current minimum substring
        minSubLen = float("infinity")   # the length of the current minimum substring
        
        left = 0 # initialize left window boundary pointer
        
        for right in range(len(s)):
            
            c = s[right] # get current character
            
            window[c] = window.get(c, 0) + 1 # add current character to current window map
            
            # if the current character is one of the required characters
            # AND it matches the required number of said characters
            if c in countT and window[c] == countT[c]:
                
                have += 1
                
            # while all required characters are present
            while have == need:
                
                # if the size of the current consideration window is smaller than the current min
                if (right - left + 1) < minSubLen:
                    
                    minSub = [left, right]          # update the minimum window boundaries
                    minSubLen = right - left + 1    # update the minimum substring length
                    
                window[s[left]] -= 1 # remove leftmost character from window
                
                # if the character remove from the window was one of the required characters
                # AND the number of said characters in the current window are less than what is required
                if s[left] in countT and window[s[left]] < countT[s[left]]:
                    
                    have -= 1
                    
                left += 1 # shift left window boundary right
                
        left, right = minSub # get left and right boundaries of minimum valid substring window
            
            
            
        # if a valid substring was found
        if minSubLen != float("infinity"):
            return s[left:right+1]
        
        else:
            return ""

def main():

    sol = Solution()
    
    s = "ADOBECODEBANC"
    t = "ABC"
    
    output = sol.minWindow(s, t)
    
    print(f"Output: \"{output}\"")

    return

if __name__ == "__main__":
    main()