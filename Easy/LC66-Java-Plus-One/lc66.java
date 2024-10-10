
/**
 * @author spetyak
 * 
 * Runtime: Beats 100% of Java submissions
 * Memory: Beats 98.06% of Java submissions
 */
public class lc66 {

    /**
     * Increments the integer represented by the array of integers by one and returns
     * the resulting integer in array form.
     * 
     * @param digits the integer array representing a single integer
     * 
     * @return the integer array representing the incremented integer
     */
    public static int[] plusOne(int[] digits) {

        int summ = 0;   //
        int carry = 1;  //

        // 
        for (int i = digits.length-1; i >= 0; i--)
        {

            summ = digits[i] + carry;

            digits[i] = summ % 10;
            carry = summ / 10;

        }

        if (carry > 0) // if there was a carry integer
        {

            // create a new integer array with an additional space to store the carry digit
            int[] newDigits = new int[digits.length + 1];

            // copy old array contents into the new array
            for (int i = 0; i < digits.length; i++)
            {
                newDigits[i+1] = digits[i];
            }

            newDigits[0] = carry; // set the first index to the carry digit

            digits = newDigits;

        }

        return digits;
        
    }



    public static void main(String[] args) {
        
        int[] digits = {4, 3, 2, 1};

        int[] output = plusOne(digits);

        for (int i = 0; i < output.length; i++)
        {
            System.out.print(output[i] + " ");
        }
        System.out.println();

    }

}