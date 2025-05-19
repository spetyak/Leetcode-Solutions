
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 92.29% of Java submissions
 */
public class lc142 {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public static class Solution {

        /**
         * Given the head of a singly linked list, returns the node where the cycle begins. 
         * If there is no cycle, returns null.
         * 
         * @param head the head of the singly linked list
         * 
         * @return The node where a cycle in the linked list begins, {@code null} if no cycle exists.
         */
        public ListNode detectCycle(ListNode head) {

            /*
             * Initialize two pointers to the head of the linked list. 
             * One pointer, slow, will move one node at a time while the other pointer, 
             * fast, will move two at a time. 
             * If the two pointers end up pointing at the same node there must be a cycle in the list.
             */
            ListNode slow = head;
            ListNode fast = head;

            boolean cycleFound = false; // a flag used to denote if a cycle exists in the list

            while (fast != null && fast.next != null)
            {

                slow = slow.next;       // take a step forward
                fast = fast.next.next;  // take two steps forward

                if (slow == fast) // if both pointers point at the same node, mark there is a cycle
                {
                    cycleFound = true;
                    break;
                }

            }

            if (!cycleFound) // if no cycle was present in the list
            {
                return null;
            }

            /*
             * Start from the head of the list with another slow pointer and iterate one step at a
             * time until the original slow pointer and the new slow pointer meet.
             * The two pointers will meet where the cycle begins.
             */
            ListNode slow2 = head; // start from the head of the list and 

            while (true)
            {

                if (slow == slow2)
                {
                    return slow;
                }

                // advance the pointers
                slow = slow.next;
                slow2 = slow2.next;

            }
            
        }

    }

    public static void main(String[] args) {

        Solution s = new Solution();
        
        ListNode ln0 = new ListNode(3);
        ListNode ln1 = new ListNode(2);
        ListNode ln2 = new ListNode(0);
        ListNode ln3 = new ListNode(-4);

        ln0.next = ln1;
        ln1.next = ln2;
        ln2.next = ln3;
        ln3.next = ln1;

        ListNode output = s.detectCycle(ln0);

        if (output == null)
        {
            System.out.println("Output: NO CYCLE FOUND");
        }
        else
        {
            System.out.println("Output: cycle starts at node with value " + output.val);
        }

    }

}