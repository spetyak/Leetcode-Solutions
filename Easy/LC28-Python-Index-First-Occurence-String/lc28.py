"""
Author: spetyak

Runtime: Beats 54.20% of Python submissions
Memory: Beats 94.20% of Python submissions

"""

class Solution(object):
    
    def strStr(self, haystack, needle):
        """
        Given two strings needle and haystack, 
        returns the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.

        Args:
            haystack (str): the string to be searched through for the substring
            needle (str): the substring to find in the larger string

        Returns:
            int: the index of the first occurrence of the needle string in the haystack string
        """
        
        # if the needle is larger than the haystack, it can't be in the haystack
        if len(needle) > len(haystack):
            
            return -1
        
        else:
            
            for i in range(len(haystack)):
                
                matchCount = 0
                
                # if the needle can still be found in the remaining part of the haystack
                if (i <= (len(haystack) - len(needle))):
                    
                    # compare from current position in haystack string looking for needle string
                    for j in range(len(needle)):
                        
                        if haystack[i+j] == needle[j]:
                            
                            matchCount += 1
                            
                    # if the full needle was found in the haystack
                    if matchCount == len(needle):
                        
                        return i
                    
            return -1
                            
                            

def main():

    sol = Solution()
    
    haystack = "sadbutsad"
    needle = "sad"
    
    print("Output: " + str(sol.strStr(haystack, needle)))

    return

if __name__ == "__main__":
    main()