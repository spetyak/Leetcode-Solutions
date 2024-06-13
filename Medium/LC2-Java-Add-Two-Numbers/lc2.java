
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 44.02% of Java submissions
 */
public class lc2 {

    public static class ListNode {

        int val;
        ListNode next;

        public ListNode() {
            this.val = 0;
            this.next = null;
        }

        public ListNode(int val) {
            this.val = val;
            this.next = null;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

    }

    public static class Solution {

        public void helper(ListNode l1, ListNode l2, int carry, ListNode currentNode) {

            int result = (l1.val + l2.val + carry) % 10; // get the ones result of the sum
            carry = (l1.val + l2.val + carry) / 10; // get the carry value of the sum

            currentNode.val = result; // set the current nodes value to the ones result

            if (l1.next != null && l2.next != null) // if both lists have items left
            {

                currentNode.next = new ListNode(); // create new result node
                currentNode = currentNode.next; // advance current pointer
                helper(l1.next, l2.next, carry, currentNode);

            }
            else if (l1.next != null) // if list 2 is done but list 1 is not
            {

                l2.val = 0; // we shouldn't add with l2 anymore since we're moving beyond it
                currentNode.next = new ListNode(); // create new result node
                currentNode = currentNode.next; // advance current pointer
                helper(l1.next, l2, carry, currentNode);

            }
            else if (l2.next != null) // if list 1 is done but list 2 is not
            {

                l1.val = 0; // we shouldn't add with l2 anymore since we're moving beyond it
                currentNode.next = new ListNode(); // create new result node
                currentNode = currentNode.next; // advance current pointer
                helper(l1, l2.next, carry, currentNode);

            }
            else // both lists do not have any remaining elements
            {

                if (carry != 0) // if the carry value given is non-zero
                {

                    currentNode.next = new ListNode(carry);

                }

            }

        }

        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

            ListNode root = new ListNode(); // initialize root node of result list
            helper(l1, l2, 0, root);
            return root;

        }

    }



    public static void main(String[] args) {

        Solution s = new Solution();
        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

        ListNode root = s.addTwoNumbers(l1, l2);

        System.out.println("Output:");
        while (root != null)
        {
            System.out.print(root.val + " ");
            root = root.next;
        }
        System.out.println();



    }

}
