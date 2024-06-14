import math

class Solution:

    def findMedianSortedArrays(self, nums1, nums2):

        combinedIndex = 0

        combinedLength = len(nums1) + len(nums2)

        # print("Combined length: " + str(combinedLength))

        median = 0.0
        
        medianIndex = (combinedLength - 1) / 2
        medianIndexSole = 0
        medianIndexCheck = False
        medianIndexLow = 0
        medianIndexHigh = 0

        if math.floor(medianIndex) == medianIndex:

            print("Median is at index " + str(int(medianIndex)))

        else:

            medianIndexCheck = True
            medianLow = int(math.floor(medianIndex))
            medianHigh = int(math.ceil(medianIndex))

            print("Median is betwween indexes " + str(medianLow) + " and " + str(medianHigh))

        # do binary search

        i = 0
        j = 0

        while i < len(nums1) and j < len(nums2):

            if combinedIndex == math.floor(medianIndex):

                if medianIndexCheck == False:

                    if nums1[i] < nums2[j]:

                        median = nums1[i]

                    else:

                        median = nums2[j]

                    break

                else:

                    if nums1[i] < nums2[j]:

                        # find low then determine where next would be
                        medianLow = nums1[i]

                        i += 1

                        if nums1[i] < nums2[j]:

                            medianHigh = nums1[i]

                        else:

                            medianHigh = nums2[j]

                        median = (medianLow + medianHigh) / 2

                        break

                    else:

                        # find low then determine where next would be
                        medianLow = nums2[j]

                        j += 1

                        if nums1[i] < nums2[j]:

                            medianHigh = nums1[i]

                        else:

                            medianHigh = nums2[j]

                        median = (medianLow + medianHigh) / 2

                        break



            if nums1[i] < nums2[j]:

                print(str(nums1[i]) + " is next number")

                i += 1
                combinedIndex += 1

            else:

                print(str(nums2[j]) + " is next number")

                j += 1
                combinedIndex += 1

        while i < len(nums1):

            if combinedIndex == math.floor(medianIndex):

                if medianIndexCheck == False:

                    median = nums1[i]

                    break

                else:

                    # do something 
                    print()

            print(str(nums1[i]) + " is next number")

            i += 1
            combinedIndex += 1

        while j < len(nums2):

            if combinedIndex == math.floor(medianIndex):

                if medianIndexCheck == False:

                    median = nums2[j]

                    break

                else:

                    # do something 
                    print()

            print(str(nums2[j]) + " is next number")

            j += 1
            combinedIndex += 1



        return median
        


def main():

    nums1 = [1, 2]
    nums2 = [3, 4]

    sol = Solution()

    print(f'Output: {sol.findMedianSortedArrays(nums1, nums2)}')

    return

if __name__ == "__main__":
    main()