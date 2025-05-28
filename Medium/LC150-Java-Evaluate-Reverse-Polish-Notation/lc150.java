import java.util.Stack;

/**
 * @author spetyak
 * 
 * Runtime: Beats 97.36% of Java submissions
 * Memory: Beats 81.72% of Java submissions
 */
public class lc150 {

    public static class Solution {

        /**
         * Given an array of strings tokens that represents an arithmetic expression 
         * in a Reverse Polish Notation, evaluates the expression.
         * 
         * @param tokens an array of strings representing integers and operands for an expression
         * 
         * @return The integer value of the Reverse Polish Notation expression.
         */
        public int evalRPN(String[] tokens) {

            Stack<Integer> stack = new Stack<>(); // a stack used to correctly evaluate RPN
            int num1 = 0;   // the first integer value being used in the operation
            int num2 = 0;   // the second integer value being used in the operation

            /*
             * Iterate through the given tokens and add integers and expression results to a stack.
             * If an operand is encountered, pop the two most recent integers from the stack to
             * perform the arithmetic operation, adding the result to the stack.
             */
            for (String token : tokens)
            {

                switch (token) {

                    case "+":
                        num1 = stack.pop();
                        num2 = stack.pop();
                        stack.push(num2 + num1);
                        break;

                    case "-":
                        num1 = stack.pop();
                        num2 = stack.pop();
                        stack.push(num2 - num1);
                        break;

                    case "*":
                        num1 = stack.pop();
                        num2 = stack.pop();
                        stack.push(num2 * num1);
                        break;

                    case "/":
                        num1 = stack.pop();
                        num2 = stack.pop();
                        stack.push(num2 / num1);
                        break;

                    default:
                        stack.push(Integer.parseInt(token));

                }

            }

            return stack.pop(); // the final element will be the result of the expression
            
        }

    }

    public static void main(String[] args) {

        Solution s = new Solution();
        
        String[] tokens = {"2", "1", "+", "3", "*"};

        int output = s.evalRPN(tokens);

        System.out.println("Output: " + output);

    }

}