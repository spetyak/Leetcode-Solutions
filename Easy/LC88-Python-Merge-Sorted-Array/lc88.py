
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 24.22% of Python submissions

"""

class Solution(object):

    def merge(self, nums1, m, nums2, n):
        """
        Given two integer arrays nums1 and nums2 (sorted in non-decreasing order) 
        and two integers m and n (representing the number of elements in nums1 and nums2 respectively),
        merges nums1 and nums2 into nums1 sorted in non-decreasing order.
        
        The integer array nums1 must be of size m + n to accomodate the in-place merging.

        Args:
            nums1 (List[int]): one of the arrays to be merged, also the destination of the merge
            m (int): the number of elements in the nums1 array
            nums2 (List[int]): the other array to be merged
            n (int): the number of elements in the nums2 array
        """

        if n == 0: # there is nothing to be added to the first list

            return

        elif m == 0: # the first list is empty, all elements in the second list can be added

            ptr1 = 0 # pointer to front of list 1
            ptr2 = 0 # pointer to front of list 2

            # copy list elements until all have been copied from list 2
            while (ptr2 < n):

                nums1[ptr1] = nums2[ptr2]
                ptr1 += 1
                ptr2 += 1

            return

        # initialize list pointers
        ptr1 = m-1      # pointer to end of list 1
        ptr2 = n-1      # pointer to end of list 2
        right = m+n-1   # pointer to true end of list 1, used to help order elements

        # compare the numbers present in each list
        while (ptr1 >= 0 and ptr2 >= 0):

            # if the number in list 2 is larger than the number in list 1, put it where right ptr is
            if (nums2[ptr2] > nums1[ptr1]):

                nums1[right] = nums2[ptr2]
                ptr2 -= 1

            # put list 1 number at right ptr
            else:

                nums1[right] = nums1[ptr1]
                ptr1 -= 1

            right -= 1

        # if not all elements of list 1 were seen
        while ptr1 >= 0:

            # if the number in list 1 is greater than the number pointed to by right, move it
            if (nums1[ptr1] > nums1[right]):
                nums1[right] = nums1[ptr1]
                right -= 1

            ptr1 -= 1

        # if not all elements of list 1 were seen, copy them to the right ptr
        while ptr2 >= 0:

            nums1[right] = nums2[ptr2]
            right -= 1
            ptr2 -= 1
    
def main():

    sol = Solution()
    
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    
    sol.merge(nums1, m, nums2, n)
    
    print(f"Output: {nums1}")

    return

if __name__ == "__main__":
    main()