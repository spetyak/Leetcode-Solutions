import math

"""
Author: spetyak

Runtime: Beats 60.33% of Python submissions
Memory: Beats 26.52% of Python submissions

"""

class Solution:

    def findMedianSortedArrays(self, nums1, nums2):

        combinedIndex = 0 # the current index stepping throught the arrays as if they were one
        combinedLength = len(nums1) + len(nums2) # the combined lengths of the arrays
        medianIndex = (combinedLength - 1) / 2 # the index of the median of the arrays
        medianIndexCheck = False # False if median is a number in the array, True if it is between indices
        medianLow = 0 # if median is between indices, the lower value
        medianHigh = 0 # if median is between indices, the higher value
        median = 0.0 # the median value of the arrays

        if math.floor(medianIndex) != medianIndex: # if the median index is between two indices

            medianIndexCheck = True
            medianLow = int(math.floor(medianIndex))
            medianHigh = int(math.ceil(medianIndex))



        i = 0 # index pointer for walking through nums1
        j = 0 # index pointer for walking through nums2

        while i < len(nums1) and j < len(nums2): # walk arrays as if they are combined

            if combinedIndex == math.floor(medianIndex): # if this index is the median index

                if medianIndexCheck == False: # if the median is a value in the array

                    if nums1[i] < nums2[j]:

                        median = nums1[i]

                    else:

                        median = nums2[j]

                    return median

                else: # the median value is between array indices

                    if nums1[i] < nums2[j]:

                        medianLow = nums1[i]

                        i += 1

                        if i < len(nums1) and nums1[i] < nums2[j]:

                            medianHigh = nums1[i]

                        else:

                            medianHigh = nums2[j]

                        median = (medianLow + medianHigh) / 2

                        return median

                    else:

                        medianLow = nums2[j]

                        j += 1

                        if j < len(nums2) and nums2[j] < nums1[i]:

                            medianHigh = nums2[j]

                        else:

                            medianHigh = nums1[i]

                        median = (medianLow + medianHigh) / 2

                        return median

            if nums1[i] < nums2[j]:

                i += 1
                combinedIndex += 1

            else:

                j += 1
                combinedIndex += 1
                


        while i < len(nums1): # if median has not been found yet and there are still numbers in nums1

            if combinedIndex == math.floor(medianIndex):

                if medianIndexCheck == False:

                    median = nums1[i]

                    return median

                else:

                    medianLow = nums1[i]
                    medianHigh = nums1[i+1]
                    
                    median = (medianLow + medianHigh) / 2

                    return median

            i += 1
            combinedIndex += 1

        while j < len(nums2): # if median has not been found yet and there are still numbers in nums2

            if combinedIndex == math.floor(medianIndex):

                if medianIndexCheck == False:

                    median = nums2[j]

                    return median

                else:

                    medianLow = nums2[j]
                    medianHigh = nums2[j+1]
                    
                    median = (medianLow + medianHigh) / 2

                    return median

            j += 1
            combinedIndex += 1



        return median
        


def main():
    
    sol = Solution()

    nums1 = [1, 2]
    nums2 = [3, 4]

    print(f'Output1: {sol.findMedianSortedArrays(nums1, nums2)}')
    
    nums1 = [1]
    nums2 = [2]

    print(f'Output2: {sol.findMedianSortedArrays(nums1, nums2)}')

    return

if __name__ == "__main__":
    main()