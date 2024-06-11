import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Iterator;



/**
 * @author spetyak
 * 
 * Runtime: Beats 10.50% of Java submissions
 * Memory: Beats 5.44% of Java submissions
 */
public class lc49 {

    public static String mergeSortString(String str) {

        if (str.length() == 1) 
        {
            return str;
        }

        String leftString = mergeSortString(str.substring(0, str.length()/2));
        String rightString = mergeSortString(str.substring(str.length()/2, str.length()));

        String outputString = "";

        int i = 0;
        int j = 0;

        while (i < leftString.length() && j < rightString.length())
        {

            if (leftString.charAt(i) < rightString.charAt(j))
            {
                outputString += leftString.charAt(i);
                i++;
            }
            else
            {
                outputString += rightString.charAt(j);
                j++;
            }

        }

        while (i < leftString.length())
        {
            outputString += leftString.charAt(i);
            i++;
        }

        while (j < rightString.length())
        {
            outputString += rightString.charAt(j);
            j++;
        }

        return outputString;

    }

    public static List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> outputList = new ArrayList<>();

        HashMap<String, ArrayList<Integer>> hm = new HashMap<>();

        if (strs.length == 1)
        {
            ArrayList<String> group = new ArrayList<>();
            group.add(strs[0]);
            outputList.add(group);
            return outputList;
        }

        for (int i = 0; i < strs.length; i++)
        {

            // System.out.print(strs[i] + " ");

            // sort the word
            String sortedStr = new String();
            if (strs[i].length() == 0)
            {
                sortedStr = strs[i];
            }
            else
            {
                sortedStr = mergeSortString(strs[i]);
            }
            
            // System.out.println("Sorted: " + sortedStr);

            ArrayList<Integer> indices = hm.get(sortedStr);
            if (indices == null)
            {
                ArrayList<Integer> newList = new ArrayList<>();
                newList.add(i);
                hm.put(sortedStr, newList);
            }
            else
            {
                indices.add(i);
                hm.put(sortedStr, indices);
            }

        }
        // System.out.println();

        // System.out.println("Number of groups: " + hm.size());

        

        Iterator<ArrayList<Integer>> anagramGroups = hm.values().iterator();

        while (anagramGroups.hasNext())
        {

            ArrayList<Integer> groupIndices = anagramGroups.next();

            ArrayList<String> anagramGroup = new ArrayList<>();

            for (int i = 0; i < groupIndices.size(); i++)
            {
                anagramGroup.add(strs[groupIndices.get(i)]);
            }

            outputList.add(anagramGroup);

        }

        return outputList;

    }


    public static void main(String[] args) {

        String[] strs1 = {"eat","tea","tan","ate","nat","bat"};

        List<List<String>> output1 = groupAnagrams(strs1);

        System.out.println("Output1:");
        for (int i = 0; i < output1.size(); i++)
        {
            List<String> list = output1.get(i);
            for (int j = 0; j < list.size(); j++)
            {
                System.out.print(list.get(j) + " ");
            }
            System.out.println();
        }

        String[] strs2 = {""};

        List<List<String>> output2 = groupAnagrams(strs2);

        System.out.println("Output2:");
        for (int i = 0; i < output2.size(); i++)
        {
            List<String> list = output2.get(i);
            for (int j = 0; j < list.size(); j++)
            {
                System.out.print(list.get(j) + " ");
            }
            System.out.println();
        }

        String[] strs3 = {"a"};

        List<List<String>> output3 = groupAnagrams(strs3);

        System.out.println("Output3:");
        for (int i = 0; i < output3.size(); i++)
        {
            List<String> list = output3.get(i);
            for (int j = 0; j < list.size(); j++)
            {
                System.out.print(list.get(j) + " ");
            }
            System.out.println();
        }

    }

}
