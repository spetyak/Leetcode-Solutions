
"""
Author: spetyak

Runtime: Beats 100% of Python submissions
Memory: Beats 54.19% of Python submissions

"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):

    def reverseBetween(self, head, left, right):
        """
        Given the head of a singly linked list and two integers left and right 
        where left <= right, reverses the nodes of the list from position left to position right, 
        and return the reversed list.

        Args:
            head (ListNode): the head of the given linked list
            left (int): the position of the left boundary of the window to be reversed
            right (int): the position of the right boundary of the window to be reversed

        Returns:
            ListNode: a linked list with the order of the nodes within the given window reversed
        """
        
        def reverse(current, i, right):
            """
            Reverses the nodes of 

            Args:
                current (ListNode): the current node being examined
                i (int): the index of the current node in the linked list
                right (int): the right boundary of the reversal window

            Returns:
                (ListNode, ListNode, ListNode): 
                A tuple of the last node of the window that will become the new front, 
                the last node encountered, and the node pointed to after the reversal window
            """
            
            # if the last node of the section to be reversed has been reached
            if (i == right):
                
                return current, current, current.next
            
            # the last node of the reverse section has not been reached yet
            else:
                
                finalHead, lastTouched, endNext = reverse(head.next, i+1, right) # advance
            
                lastTouched.next = current # connect the last touched node's next pointer to the current node
                
                return finalHead, current, endNext
        
        
        
        i = 0       # the index of the current node in the linked list
        left -= 1   # the left boundary of the reversal window
        right -= 1  # the right boundary of the reversal window
        
        finalHead = None    # the last node in the reversal window, becomes the first node in the window once reversed
        endNext = None      # the node (or null) pointed to by the final node of the window prior to being reversed
        lastTouched = None  # the last node touched when reversing, becomes the last node in the window once reversed
        
        # if the first node is part of the reversal window
        if left == 0:
            
            # if there is only a single node in the list
            if head.next == None:
                
                return head
            
            else:
                
                # reverse and reassign head
                finalHead, lastTouched, endNext = reverse(head, i, right)
                head = finalHead
                lastTouched.next = endNext
                
        else:
            
            # advance to the node before the reversal window
            current = head
            while i < left-1:
                
                current = current.next
                i += 1
            
            # reverse
            finalHead, lastTouched, endNext = reverse(current.next, i+1, right)
            
            current.next = finalHead
            lastTouched.next = endNext
            
        
        
        return head
    
def main():

    sol = Solution()
    
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    left = 4
    right = 4
    
    head = sol.reverseBetween(head, left, right)
    
    while (head != None):
        
        print(head.val)
        head = head.next

    return

if __name__ == "__main__":
    main()