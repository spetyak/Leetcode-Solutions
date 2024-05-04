import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class lc30 {

    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> returnList = new ArrayList<>();

        int startIndex = 0;
        int endIndex = words.length * words[0].length();

        while (endIndex <= s.length()) {

            List<String> wordList = new ArrayList<>(Arrays.asList(words));

            String sub = s.substring(startIndex, endIndex);

            for (int i = 0; i < words.length; i++) {

                String subWord = sub.substring(i*words[0].length(), (i+1)*words[0].length());

                if (wordList.contains(subWord)) {

                    wordList.remove(wordList.indexOf(subWord));

                }

            }

            if (wordList.size() == 0) {

                returnList.add(startIndex);

            }
            
            startIndex += 1;
            endIndex +=  1;

        }

        System.out.println(returnList);

        return returnList;

    }

    public static void main(String[] args) {

        String s = "ababaab";
        String[] words = {"ab","ba", "ba"};
    
        lc30 n = new lc30();
        
        n.findSubstring(s, words);
    
    }

}

