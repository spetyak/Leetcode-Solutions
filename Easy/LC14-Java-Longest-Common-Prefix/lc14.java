
public class lc14 {

    public static String longestCommonPrefix(String[] strs)
    {

        if (strs.length == 0)
        {
            return "";
        }

        String common = strs[0];
        int prefixEnd = strs[0].length();

        for (int i = 1; i < strs.length; i++)
        {

            
            
        }
        System.out.println("Common prefix ends at: " + prefixEnd);

        return common.substring(0, prefixEnd);

    }

    public static void main(String[] args)
    {

        String[] strs = {"ab", "a"};

        System.out.println("Output: " + longestCommonPrefix(strs));

    }

}
