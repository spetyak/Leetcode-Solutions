
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 99.86% of Java submissions
 */
public class lc22 {

    public static List<String> output; // the list of all possible combinations of n well-formed parentheses

    /**
     * Builds all possible combinations of parentheses. 
     * The combinations that contain {@code n} well-formed parentheses are added to the output list.
     * 
     * @param currentStr the current string of parentheses being built
     * @param open the number of open parentheses not yet used in the string
     * @param close the number of closed parentheses not yet used in the string
     */
    public static void generate(StringBuilder currentStr, int open, int close) {

        // base case
        if (open == 0 && close == 0)
        {
            output.add(currentStr.toString());
            return;
        }

        if (open > 0)
        {
            currentStr.append('(');
            generate(currentStr, open-1, close);
            currentStr.deleteCharAt(currentStr.length()-1);
        }

        if (close > open)
        {
            currentStr.append(')');
            generate(currentStr, open, close-1);
            currentStr.deleteCharAt(currentStr.length()-1);
        }

    }

    /**
     * Generates all well-formed combinations of {@code n} pairs of parentheses.
     * 
     * @param n the number of pairs of parentheses that should be present
     * 
     * @return All possible well-formed combinations of {@code n} pairs of parentheses
     */
    public static List<String> generateParenthesis(int n) {

        output = new ArrayList<>(); // initialize the output list

        generate(new StringBuilder(""), n, n); // build parentheses combinations

        return output;

    }

    public static void main(String[] args) {

        int n = 3;

        List<String> output = generateParenthesis(n);

        Iterator<String> iter = output.iterator();

        System.out.println("Output:");
        while (iter.hasNext())
        {
            System.out.println(iter.next() + " ");
        }
        System.out.println();
        
    }

}