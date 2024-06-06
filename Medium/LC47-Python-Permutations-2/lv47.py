"""
Author: spetyak

Runtime: Beats 68.55% of Python submissions
Memory: Beats 94.48% of Python submissions

"""

class Solution:

    def recursive(self, myDict, current, outList):

        if len(myDict) == 0: # if nothing is left in the dictionary

            outList.append(current) 

        else:

            for key in list(myDict.keys()): # loop through the remaining keys in the dictionary

                if myDict.get(key) == 1: # if we have the final element

                    del myDict[key]
                    current.append(key)
                    self.recursive(myDict.copy(), current.copy(), outList)
                    current.pop()
                    myDict[key] = 1
                    

                else:

                    myDict[key] = myDict.get(key) - 1
                    current.append(key)
                    self.recursive(myDict.copy(), current.copy(), outList)
                    current.pop()
                    myDict[key] = myDict.get(key) + 1

        return 

    def permuteUnique(self, nums):

        myDict = {}

        for i in range(len(nums)):

            if myDict.get(nums[i]) == None:

                myDict[nums[i]] = 1

            else:

                myDict[nums[i]] += 1

        current = []
        outList = []

        self.recursive(myDict.copy(), current.copy(), outList)
                

        return outList
        