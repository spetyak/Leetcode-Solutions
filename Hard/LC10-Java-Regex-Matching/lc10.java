
/**
 * @author spetyak
 * 
 * Runtime: Beats 63.89% of Java submissions
 * Memory: Beats 95.46% of Java submissions
 */
public class lc10 {

    /**
     * Given an input string {@code s} and a pattern {@code p}, 
     * determines if the two strings match according to regular expression rules
     * with support for {@code '.'} and {@code '*'} where:
     * <ul>
     *      <li>{@code '.'} matches any single character</li>
     *      <li>{@code '*'} matches zero or more of the preceding element</li>
     * </ul>
     * 
     * @param s the string to be checked
     * @param p the rule string
     * 
     * @return {@code true} if the given string matches the rule string, {@code false} if not
     */
    public static boolean isMatch(String s, String p) {

        /*
         * Create a table to perform a comparison of the two strings using dynamic programming
         */
        boolean[][] dpTable = new boolean[s.length() + 1][p.length() + 1];

        /*
         * Mark the first index of the table as true.
         * The first row and column of the table contain the null character,
         * so only the null character and itself can be considered to match.
         */
        dpTable[0][0] = true;

        /*
         * Go through null row for pattern string and mark any '*'s 
         * that follow a indefinite characters in the rule string to be true.
         * This is done to ensure the case of a string whose pattern string allows
         * for the first starred characters to not exist in the string to pass,
         * while later starred characters who follow two characters (such as 'ab*')
         * will have to be examined more closely later on as part of the 
         * dynamic programming algorithm.
         */
        for (int i = 1; i < p.length()+1; i++)
        {
            if (p.charAt(i - 1) == '*')
            {
                dpTable[0][i] = dpTable[0][i - 2];
            }
        }



        for (int sIndex = 0; sIndex < s.length(); sIndex++)
        {

            for (int pIndex = 0; pIndex < p.length(); pIndex++)
            {

                /*
                 * If the current characters being compared match (or the rule string
                 * character is a '.'), inherit the value of the table value diagonally
                 * left of the current position.
                 */
                if (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '.')
                {
                    dpTable[sIndex+1][pIndex+1] = dpTable[sIndex][pIndex];
                }

                /*
                 * If the rule string character being considered is a '*', 
                 * determine if the character preceding the starred character
                 * has a true value for the current row, and take it if so.
                 * This indicates the absence of the starred character in the string.
                 */
                else if (p.charAt(pIndex) == '*' && dpTable[sIndex+1][pIndex-1] == true)
                {
                    dpTable[sIndex+1][pIndex+1] = dpTable[sIndex+1][pIndex-1];
                }

                /*
                 * If the rule string character being considered is a '*' 
                 * AND the character preceding the starred character has a 
                 * false value for the current row, determine the truth value
                 * for the position directly above the current one.
                 * This indicates the presence/repetition of the starred character in the string.
                 */
                else if (p.charAt(pIndex) == '*' && (p.charAt(pIndex-1) == s.charAt(sIndex) || p.charAt(pIndex-1) == '.'))
                {
                    dpTable[sIndex+1][pIndex+1] = dpTable[sIndex][pIndex+1];
                }

            }

        }

        

        return dpTable[s.length()][p.length()];

    }

    public static void main(String[] args) {

        String s = "aa";
        String p = "a*";

        System.out.println("Output: " + isMatch(s, p));

    }

}