import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * @author spetyak
 * 
 * Runtime: Beats 6.13% of Java submissions
 * Memory: Beats 76.36% of Java submissions
 */
public class lc126 {

    public static List<List<String>> outputList; // the list of the shortest transformation sequences from beginWord to endWord
    public static HashMap<String, List<String>> parentMap; // a map of a word to it's parent word(s) in the connectivity graph

    /**
     * Determines whether the two given strings are adjacent (differ by a single letter) or not.
     * 
     * @param a the first string to be compared
     * @param b the second string to be compared
     * 
     * @return {@code true} if the strings are adjacent, {@code false} if not.
     */
    public static boolean diff(String a, String b) {

        int difference = 0; // the amount by which the two given strings differ

        for (int i = 0; i < a.length(); i++)
        {
            if (a.charAt(i) != b.charAt(i))
            {
                difference++;
            }
        }

        return difference == 1;

    }

    /**
     * Performs a depth-first search from endWord to beginWord, creating a ladder of adjacent words
     * that are added to the output list once beginWord is reached.
     * 
     * @param currentWord the current word node being considered
     * @param beginWord the starting word of the transformation sequence
     * @param ladder the words of the transformation sequence from beginWord to endWord
     */
    public static void dfs(String currentWord, String beginWord, List<String> ladder) {

        // if beginWord has been reached, add the current ladder to the output list
        if (currentWord.equals(beginWord))
        {
            outputList.add(new ArrayList<>(ladder));
            return;
        }

        // travel to the current word's parents in the graph, 
        // adding them each to the beginning of the ladder
        List<String> wordList = parentMap.get(currentWord);
        if (wordList != null)
        {

            for (int i = 0; i < wordList.size(); i++)
            {
                String word = wordList.get(i);
                ladder.add(0, word);
                dfs(word, beginWord, ladder);
                ladder.remove(0);
            }

        }

    }

    /**
     * Given two words, {@code beginWord} and {@code endWord}, and a dictionary {@code wordList}, 
     * returns all the shortest transformation sequences from {@code beginWord} to {@code endWord} 
     * where each word in the sequence differs by one letter, or an empty list if 
     * no such sequence exists.
     * 
     * @param beginWord the starting word of the transformation sequence
     * @param endWord the ending word of the transformation sequence
     * @param wordList the words that may be used as part of the transformation sequence
     * 
     * @return A list of all of the shortest transformation sequences from {@code beginWord} to {@code endWord} where each word in the sequence differs by one letter.
     */
    public static List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {

        outputList = new ArrayList<>();

        // if the end word does not exist in the list it is impossible to create a valid sequence
        if (!wordList.contains(endWord))
        {
            return outputList;
        }

        /*
         * Search for the index of beginWord in the word list.
         * If it is present, note its index.
         * If it is NOT present, add it to the front of the word list.
         */

        int beginWordIndex = -1;

        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList.get(i).equals(beginWord))
            {
                beginWordIndex = i;
                break;
            }
        }

        if (beginWordIndex < 0)
        {
            beginWordIndex = 0;
            wordList.add(beginWordIndex, beginWord);
        }
        
        /*
         * Initialize a boolean array to keep track of which word nodes 
         * have been visited in the graph.
         * Nodes will be updated by level from beginWord.
         */
        boolean visited[] = new boolean[wordList.size()]; 

        /*
         * Create a matrix of all the word connectivities.
         * Word connections that differ by 1 are marked with true boolean values.
         */
        boolean wordMatrix[][] = new boolean[wordList.size()][wordList.size()];
        for (int i = 0; i < wordMatrix.length; i++)
        {
            String word1 = wordList.get(i);
            for (int j = i+1; j < wordMatrix.length; j++)
            {
                boolean difference = diff(word1, wordList.get(j));
                wordMatrix[i][j] = difference;
                wordMatrix[j][i] = difference;
            }
        }

        parentMap = new HashMap<>(); // a map of the parents for a given word, will help with DFS

        Queue<List<Integer>> q = new LinkedList<>();    // a queue to perform a BFS with
        List<Integer> pushList = new ArrayList<>();     // the list of new nodes found at each level
        pushList.add(beginWordIndex);
        q.offer(pushList);

        boolean endFound = false; // flag to stop processing the queue once endWord has been found

        while (!q.isEmpty())
        {

            List<Integer> levelList = q.poll(); // get the next level of the graph branching from beginWord
            pushList = new ArrayList<>();

            for (int i = 0; i < levelList.size(); i++)
            {

                int poppedWordIndex = levelList.get(i); // the index of the word from the popped list in wordList

                // consider the current popped word's connections
                for (int j = 0; j < wordMatrix.length; j++)
                {

                    /*
                     * To add the current word to the push list and update the parent map it must:
                     * - Be adjacent to the popped word
                     * - Not already exist in the level list that is being examined
                     * - Not have been in a previously visited level
                     */
                    if (wordMatrix[poppedWordIndex][j] && !levelList.contains(j) && !visited[j])
                    {

                        String currentWord = wordList.get(j);

                        // flag that the end word is found and no further levels need be considered
                        if (currentWord.equals(endWord))
                        {
                            endFound = true;
                        }

                        List<String> parentList = parentMap.get(currentWord);

                        if (parentList == null)
                        {
                            parentList = new ArrayList<>();
                        }

                        if (!parentList.contains(wordList.get(poppedWordIndex)))
                        {
                            parentList.add(wordList.get(poppedWordIndex));
                            pushList.add(j);
                        }

                        parentMap.put(currentWord, parentList);

                    }

                }

            }

            // mark all words at this level as visited to avoid cycles in the graph
            for (int j = 0; j < levelList.size(); j++)
            {
                visited[levelList.get(j)] = true;
            }

            if (endFound) // if the endWord was flagged, there is no reason to continue the search
            {
                break;
            }
            else if (!pushList.isEmpty())
            {
                q.offer(pushList);
            }
            

        }

        /*
         * Create the word transformation sequences using DFS
         */
        List<String> ladder = new ArrayList<>();
        ladder.add(endWord);
        dfs(endWord, beginWord, ladder);

        return outputList;

    }

    public static void main(String[] args) {

        // String beginWord = "hit";
        // String endWord = "cog";
        // List<String> wordList = new ArrayList<>(Arrays.asList("hot","dot","dog","lot","log","cog"));

        String beginWord = "red";
        String endWord = "tax";
        List<String> wordList = new ArrayList<>(Arrays.asList("ted","tex","red","tax","tad","den","rex","pee"));


        List<List<String>> output = findLadders(beginWord, endWord, wordList);

        System.out.println("Output:");
        Iterator<List<String>> outerItr = output.iterator();
        while (outerItr.hasNext())
        {
            System.out.println(outerItr.next().toString());
        }

    }

}