
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 70.98% of Java submissions
 */
public class lc82 {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     * Given the head of a sorted linked list, deletes all nodes that have duplicate numbers, 
     * leaving only distinct numbers from the original list. 
     * The returned list should still be in sorted order.
     * 
     * @param head the head of the sorted linked list to remove duplicates from
     * 
     * @return the head of the sorted linked list with duplicate elements removed
     */
    public static ListNode deleteDuplicates(ListNode head) {

        if (head == null)
        {
            return null;
        }
        else if (head.next == null)
        {
            return head;
        }

        // remove leading duplicate elements
        while (head.next != null && head.val == head.next.val)
        {

            // while the current element and next element are the same
            while (head.next != null && head.val == head.next.val)
            {
                head = head.next;
            }
        
            // check if new number found repeats
            if (head.next != null && head.next.next != null && head.next.val == head.next.next.val)
            {
                head = head.next;
            }
            else 
            {
                head = head.next;
                break;
            }

        }

        // front has at least one unique node (if any remain)

        if (head == null)
        {
            return head;
        }
        else if (head.next == null)
        {
            return head;
        }

        

        ListNode left = head;
        ListNode right = head.next;
        boolean repeatsFound = false;
        while (right.next != null)
        {

            repeatsFound = false; // reset repeats flag

            // while numbers are repreating
            while (right.next != null && right.val == right.next.val)
            {
                repeatsFound = true;
                right = right.next;
            }

            if (right.next == null) // end of list reached, work is done
            {

                if (left.next != right) // if repeats have been found, connect around them
                {
                    left.next = right.next;
                }

                return head;
            }
            else
            {

                if (right.next.next != null)
                {

                    if (repeatsFound && right.next.val == right.next.next.val) // more duplicates, need to run right loop again
                    {
                        right = right.next;
                    }
                    else
                    {

                        if (left.next == right) // no repeats, advance
                        {
                            left = left.next;
                            right = right.next;
                        }
                        else // repeats found
                        {
                            left.next = right.next; // point around duplicates
                            left = right.next;      // move to next non-duplicate space
                            right = left.next;      // put right pointer after left
                        } 

                    }

                }
                else
                {

                    if (left.next != right) // if repeats have been found, connect around them
                    {
                        left.next = right.next;
                    }

                    return head;

                }

            }

        } 
        
        return head;

    }

    public static void main(String[] args) {
        
        // 1 2 3 3 4 4 5
        ListNode head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(5))))))));

        head = deleteDuplicates(head);

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