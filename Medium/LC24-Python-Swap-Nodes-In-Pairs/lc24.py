"""
Author: spetyak

Runtime: Beats 37.42% of Python submissions
Memory: Beats 23.04% of Python submissions

"""

class Solution(object):
    
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next

    def swapPairs(self, head):
        """
        Given a linked list, swaps every two adjacent nodes.

        Args:
            head (ListNode): The head of the given linked list

        Returns:
            ListNode: The linked list with adjacent nodes swapped
        """
        
        # add a dummy head to help with swapping first elements
        dummyHead = Solution.ListNode(-1, head)
        current = dummyHead
            
        # while there are at least two nodes ahead of the current node
        while (current.next != None and current.next.next != None):
            
            temp1 = current.next
            temp2 = temp1.next
            
            # swap around node pointers
            temp1.next = temp2.next
            temp2.next = temp1
            current.next = temp2
            
            # advance to next pair
            current = current.next.next
                
        head = dummyHead.next # disregard the dummy head node when returning

            
        
        return head

def main():

    sol = Solution()
    
    list = sol.ListNode(1)
    list.next = sol.ListNode(2)
    list.next.next = sol.ListNode(3)
    list.next.next.next = sol.ListNode(4)

    output = sol.swapPairs(list)
    
    print("Output:")
    while (output != None):
        print(output.val)
        output = output.next

    return

if __name__ == "__main__":
    main()
