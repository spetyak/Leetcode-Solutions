import java.util.HashMap;

/**
 * @author spetyak
 * 
 * Runtime: Beats 18.46% of Java submissions
 * Memory: Beats 41.80% of Java submissions
 */
public class lc14 {

    /**
     * A class representing a node of a tree structure.
     * A node has a single character and a hashmap of it's child nodes.
     */
    public static class Node {

        char c;
        HashMap<Character, Node> childMap;

        public Node()
        {
            this.c = '\0';
            this.childMap = new HashMap<>();
        }

        public Node(Character c)
        {
            this.c = c;
            this.childMap = new HashMap<>();
        }

        /**
         * Adds the given node as a child to this node.
         * @param n the node to be added as a child to this node.
         */
        public void addChild(Node n)
        {
            childMap.put(n.c, n);
        }

        /**
         * Returns a child node if and only if this node has only one child.
         * @return this node's singular child node, or {@code null} if there are multiple children.
         */
        public Node getSingleChild()
        {
            if (getNumberChildren() != 1) // if there is more than one child
            {
                return null;
            }
            else
            {
                return childMap.values().iterator().next();
            }
        }

        /**
         * Returns the child of this node having the given character, or {@code null} if no such child exists.
         * @param c the character to be search for among the child nodes.
         * @return the child node who has the character 'c', or {@code null} if no such child exists.
         */
        public Node getChild(Character c)
        {
            return childMap.get(c);
        }

        /**
         * Returns the number of children this node has.
         * @return the number of children this node has.
         */
        public int getNumberChildren()
        {
            return childMap.size();
        }

        /**
         * Returns {@code true} if this node has a child with the given character 'c'.
         * @param c the character to be searched for among the child nodes.
         * @return {@code true} if this node has a child with character 'c', {@code false} if not.
         */
        public boolean hasChild(Character c)
        {
            return childMap.containsKey(c);
        }

    }

    /**
     * Determines the longest common prefix amongst an array of strings.
     * 
     * @param strs the strings to be examined for a common prefix.
     * 
     * @return the longest common prefix shared by all strings given in the array.
     */
    public static String longestCommonPrefix(String[] strs) {

        // make a trie
        Node root = new Node();
        Node current;
        Character currentChar;
        
        // examine all strings in the given array
        for (int i = 0; i < strs.length; i++)
        {

            current = root;

            if (strs[i].length() == 0) // empty string
            {
                Node newNode = new Node('\0');
                current.addChild(newNode);
            }
            else
            {

                // examine all characters in the current string
                for (int j = 0; j < strs[i].length(); j++)
                {

                    currentChar = strs[i].charAt(j);

                    if (current.hasChild(currentChar)) // the character already exists in this branch of the trie
                    {
                        current = current.getChild(currentChar);
                    }
                    else // the character does NOT exist in this branch of the trie
                    {
                        Node newNode = new Node(currentChar);
                        current.addChild(newNode);
                        current = newNode;
                    }

                }

                // add final null node to represent end of branch
                Node newNode = new Node('\0');
                current.addChild(newNode);
                current = newNode;

            }

        }

        current = root;

        StringBuilder s = new StringBuilder();

        // while there are more branches to traverse
        while (current.getNumberChildren() != 0)
        {

            // if the branch only has one child
            if (current.getNumberChildren() == 1)
            {

                current = current.getSingleChild();

                if (current.c == '\0')
                {
                    break; // no need to add null character
                }
                else
                {
                    s.append(current.c);
                }
                
            }
            else
            {
                break;
            }

        }



        return s.toString();

    }

    public static void main(String[] args)
    {

        String[] strs = {"ab", "a"};

        System.out.println("Output: " + longestCommonPrefix(strs));

    }

}