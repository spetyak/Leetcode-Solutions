
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 95.78% of Java submissions
 */
public class lc58 {

    /**
     * Returns the length of the last word in the given string.
     * 
     * @param s the string of words to be parsed
     * 
     * @return the length of the last word in the given string
     */
    public static int lengthOfLastWord(String s) {

        s = s.trim(); // remove white space from ends

        // travel from end of string to start
        for (int i = s.length()-1; i >= 0; i--)
        {

            // if the current character is a space, we've reached past the last word
            if (s.charAt(i) == ' ')
            {
                return (s.length() - i) - 1; // return the last word length
            }

        }

        return s.length(); // the whole string is a single word
        
    }

    

    public static void main(String[] args) {

        String s = "    test to    be  sure      ";
        
        System.out.println("Output: " + lengthOfLastWord(s));

    }

}
