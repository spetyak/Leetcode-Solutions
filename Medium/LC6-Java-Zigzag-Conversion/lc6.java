import java.util.LinkedList;
import java.util.Queue;

/*
 * @author spetyak
 * 
 * Runtime: Beats 45.97% of Java submissions
 * Memory: Beats 76.12% of Java submissions
 */
public class lc6 {

    /**
     * Modifies string to read as if it were scrambled in a zigzag fashion
     * 
     * @param s         the string to be rearranged
     * @param numRows   the number of rows that make up a straight line of the zigzag
     * 
     * @return the rearranged string
     */
    public static String convert(String s, int numRows) {



        // if there is only 1 row there is no zigzag to change the order
        if (numRows == 1) 
        {
            return s;
        }



        StringBuilder str = new StringBuilder(s);

        // create the queues of characters that will hold the input strings letters
        @SuppressWarnings("unchecked")
        Queue<Character>[] q = new Queue[numRows];
        for (int i = 0; i < numRows; i++)
        {
            q[i] = new LinkedList<>();
        }



        // add the letters in the input string to the queues (rows) in a zigzag fashion

        int stringIndex = 0;
        int queueIndex = 0;
        int step = 1;

        while (stringIndex < str.length()) {

            q[queueIndex].add(str.charAt(stringIndex));

            stringIndex++;
            queueIndex += step;

            if (queueIndex == numRows - 1)
            {
                step = -1;
            }
            else if (queueIndex == 0)
            {
                step = 1;
            }

        }



        // empty the queue and alter the input string to reflect a zigzag conversion of the original string

        stringIndex = 0;

        for (int i = 0; i < numRows; i++) {

            while (!q[i].isEmpty()) {

                str.setCharAt(stringIndex, q[i].remove());

                stringIndex++;

            }

        }

        return str.toString();
    }

    public static void main(String[] args) {

        String s = "AB";
        int numRows = 2;

        System.out.println("Output: " + convert(s, numRows));

    }

}