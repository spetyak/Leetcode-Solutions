import java.util.HashMap;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 84.00% of Java submissions
 */
public class lc138 {

    /**
     * Description
     * 
     * @param head
     * 
     * @return
     */
    public static Node copyRandomList(Node head) {

        // use a hashmap mapping old pointers to new copy pointers

        if (head == null)
        {
            return null;
        }

        HashMap<Node, Node> hm = new HashMap<>();

        Node existingCopy = null;

        Node current = head;
        Node copy = new Node(head.val);
        hm.put(current, copy);

        while (current != null)
        {

            // make copy of node

            copy = hm.get(current);

            if (current.next != null) // check if next pointer is null or not
            {

                existingCopy = hm.get(current.next); // attempt to find existing copy of next

                if (existingCopy != null) // if existing copy found, simply populate next field
                {
                    copy.next = existingCopy;
                }
                else // if existing copy not found
                {
                    Node newCopy = new Node(current.next.val);      // make new copy of next
                    hm.put(current.next, newCopy);                  // add next and copy to map
                    copy.next = newCopy;                            // populate copy next field
                }

            }

            if (current.random != null) // check if random pointer is null or not
            {

                existingCopy = hm.get(current.random); // attempt to find existing copy of random

                if (existingCopy != null) // if existing copy found, simply populate random field
                {
                    copy.random = existingCopy;
                }
                else // if existing copy not found
                {
                    Node newCopy = new Node(current.random.val);    // make new copy of random
                    hm.put(current.random, newCopy);                // add random and copy to map
                    copy.random = newCopy;                          // populate copy random field
                }

            }

            current = current.next;

        }

        current = hm.get(head);

        return current;
        
    }

    public static void main(String[] args) {

        Node n1 = new Node(7);
        Node n2 = new Node(13);
        Node n3 = new Node(11);
        Node n4 = new Node(10);
        Node n5 = new Node(1);

        n1.next = n2;
        n1.random = null;

        n2.next = n3;
        n2.random = n1;

        n3.next = n4;
        n3.random = n5;

        n4.next = n5;
        n4.random = n3;

        n5.next = null;
        n5.random = n1;

        copyRandomList(n1);


    }

}