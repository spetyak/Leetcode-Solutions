
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 96.64% of Java submissions
 */
public class lc86 {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Given the head of a linked list and a value x, partitions the linked list 
     * such that all nodes less than x come before nodes greater than or equal to x.
     * The original relative order of the nodes is preserved in each of the two partitions.
     * 
     * @param head the head of a linked list
     * @param x the value to partition the list with
     * 
     * @return
     */
    public static ListNode partition(ListNode head, int x) {
        
        // if list is empty or a single element, no changes need to be made
        if (head == null || head.next == null)
        {
            return head;
        }

        ListNode current = head;                            // pointer used to traverse list
        ListNode lastLess = (head.val < x) ? head : null;   // pointer to last value less than x

        // while the end of the list has not been reached
        while (current != null && current.next != null)
        {

            // if the next value is less than x
            if (current.next.val < x)
            {

                // if we have not found a value less than x so far
                if (lastLess == null)
                {

                    ListNode nodeToMove = current.next; // pointer to the front of the lesser-than-x range being moved
                    ListNode findLess = current.next;   // pointer to the end of the lesser-than-x range being moved

                    // step until end or next value is NOT less than x
                    while (findLess.next != null && findLess.next.val < x)
                    {
                        findLess = findLess.next;
                    }

                    current.next = findLess.next;   // move current next pointer past lesser-than-x range
                    findLess.next = head;           // point end of lesser-than-x range to list head
                    lastLess = findLess;            // the last value less than x so far is the end of the range
                    head = nodeToMove;              // set the head of the list to be the front of the lesser-than-x range

                }
                else if (lastLess == current) // the current value is the last value less than x found so far
                {

                    lastLess = lastLess.next; // advance last less pointer

                }
                else
                {

                    ListNode nodeToMove = current.next; // pointer to the front of the lesser-than-x range being moved
                    ListNode findLess = current.next;   // pointer to the end of the lesser-than-x range being moved

                    // step until end or next value is NOT less than x
                    while (findLess.next != null && findLess.next.val < x)
                    {
                        findLess = findLess.next;
                    }

                    current.next = findLess.next;   // move current next pointer past lesser-than-x range
                    findLess.next = lastLess.next;  // place lesser-than-x range between last less pointer and the next greater value
                    lastLess.next = nodeToMove;     // point the last less pointer to the front of the lesser-than-x range
                    lastLess = findLess;            // set the end of the lesser-than-x range to be the last less value

                }

            }
            
            current = current.next; // advance to next value

        }



        return head;

    }

    public static void main(String[] args) {
        
        ListNode head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
        int x = 3;

        head = partition(head, x);

        System.out.println("Output:");
        ListNode current = head;
        while (current != null)
        {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();

    }

}
