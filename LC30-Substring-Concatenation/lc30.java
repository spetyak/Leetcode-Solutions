import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class lc30 {

    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> returnList = new ArrayList<>();

        int strLength = s.length();
        int wordLength = words[0].length();
        int wordsLength = words.length;
        int concatLength = wordsLength * wordLength;

        Integer count = null;

        Map<String, Integer> wordMap = new HashMap<>();

        Integer checkNum = null;
        Integer occurences = null;

        String currentWord = "";
        Integer currentCount = null;

        boolean allMatch = true;

        String currentWords = "";
        Map<String, Integer> currentMap = null;

        for (int i = 0; i < wordsLength; i++)
        {
            count = wordMap.get(words[i]);
            if (count == null)
            {
                count = 1;
            }
            else
            {
                count++;
            }
            wordMap.put(words[i], count);
        }

        for (int i = 0; i < strLength-concatLength+1; i++)
        {

            allMatch = true;

            currentWords = s.substring(i, i+concatLength);
            currentMap = new HashMap<>();

            for (int j = 0; j < wordsLength; j++)
            {

                currentWord = currentWords.substring(wordLength*j, wordLength*(j+1));

                // System.out.println(currentWord);

                currentCount = currentMap.get(currentWord);

                if (currentCount == null)
                {
                    currentCount = 1;
                }
                else
                {
                    currentCount++;
                }

                currentMap.put(currentWord, currentCount);

            }

            for (int j = 0; j < wordsLength; j++)
            {

                currentWord = words[j];

                checkNum = currentMap.get(currentWord);
                occurences = wordMap.get(currentWord); // cannot be null since these are words we know we have

                if (checkNum == null)
                {
                    allMatch = false;
                    break;
                }
                else
                {

                    if (checkNum.equals(occurences))
                    {
                        // good
                        allMatch = true;
                    }
                    else
                    {
                        // bad
                        allMatch = false;
                        break;
                    }

                }

            }

            if (allMatch == true)
            {
                // System.out.println(currentWords);
                returnList.add(i);
            }

            // System.out.println();

        }

        return returnList;

    }

    public static void main(String[] args) {

        String s = "barfoothefoobarman";
        String[] words = {"foo","bar"};
    
        lc30 n = new lc30();
        
        List<Integer> indeces = n.findSubstring(s, words);

        System.out.println("Indices: " + indeces);
    
    }

}

