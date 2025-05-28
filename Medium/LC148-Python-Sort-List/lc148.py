
"""
Author: spetyak

Runtime: Beats 77.66% of Python submissions
Memory: Beats 87.45% of Python submissions

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:

    def sortList(self, head):
        """
        Given the head of a linked list, returns the list after sorting it in ascending order.

        Args:
            head (Optional[ListNode]): the head of the linked list to be sorted

        Returns:
            Optional[ListNode]: The sorted linked list.
        """

        def mergeSort(h):
            """
            Given the head of a linked list, performs merge sort.

            Args:
                h (Optional[ListNode]): the head of the linked list to be sorted

            Returns:
                Optional[ListNode]: The sorted linked list.
            """

            # if the linked list has only one element, return the list
            if (h.next is None):
                return h
            

            
            # find list midpoint, split at midpoint, and sort list halves

            slow = h
            fast = h.next # set as next so that in an even length list the midpoint is the node BEFORE the middle

            while (fast is not None and fast.next is not None):

                slow = slow.next
                fast = fast.next.next

            list1 = h           # point to start of first list half
            list2 = slow.next   # point to start of second list half

            slow.next = None # split first and second half of list

            # sort list halves
            list1 = mergeSort(list1)
            list2 = mergeSort(list2)

            # initialize a list to merge the list halves into with a dummy node to make
            # merging easier
            mergedList = temp = ListNode(0)

            # merge list halves

            while list1 is not None and list2 is not None:

                if (list1.val < list2.val):
                    temp.next = list1
                    list1 = list1.next

                else:
                    temp.next = list2
                    list2 = list2.next

                temp = temp.next

            if list1 is not None:

                temp.next = list1

            if list2 is not None:

                temp.next = list2

            return mergedList.next
            


        if head is None: # if the given list is empty
            return None          

        head = mergeSort(head) # perform merge sort on the linked list

        return head
                
                
    
def main():

    sol = Solution()

    head = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))

    output = sol.sortList(head)

    current = output
    print("Output: [", end="")
    while (current is not None):
        print(current.val, end=" ")
        current = current.next
    print(end="]\n")

    return

if __name__ == "__main__":
    main()