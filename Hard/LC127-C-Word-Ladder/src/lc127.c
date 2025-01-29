
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats 41.38% of C submissions
 * Memory: Beats 56.90% of C submissions
 */

#define MAX_WORD_LENGTH 10

struct QueueNode {
    char* word;
    int level;
};

struct Queue {
    struct QueueNode* nodes;
    int head;
    int tail;
    int size;
};

/*
 * Add a word to the end of the queue.
 *
 * @param q the given queue
 * @param newWord the word to add to the queue
 * @param level the level of the word being added to the queue
 */
void enqueue(struct Queue* q, char* newWord, int level) {

    q->nodes[q->tail].word = newWord;
    q->nodes[q->tail].level = level;
    q->tail++;
    q->size++;

}

/*
 * Remove and return the head of the queue.
 *
 * @param q the given queue
 * 
 * @return The head queue node.
 */
struct QueueNode dequeue(struct Queue* q) {
    
    q->size--;

    return q->nodes[q->head++];

}

/*
 * Determines whether the two given strings are adjacent (differ by a single letter) or not.
 *
 * @param a the first string to be compared
 * @param b the second string to be compared
 * @param wordSize the size of the words being compared
 * 
 * @return 1 if the strings are adjacent, 0 if not.
 */
int diff(char* a, char* b, int wordSize) {

    int difference = 0; // the amount by which the two given strings differ

    for (int i = 0; i < wordSize; i++)
    {

        if (a[i] != b[i])
        {

            difference++;

            if (difference > 1)
            {
                return 0;
            }

        }

    }

    return difference == 1;

}

/*
 * Given two words, beginWord and endWord, and a dictionary wordList, 
 * returns the length of the shortest transformation sequence from beginWord to endWord 
 * where each word in the sequence differs by one letter, or an empty list if 
 * no such sequence exists. 
 *
 * @param beginWord the starting word of the transformation sequence
 * @param endWord the ending word of the transformation sequence
 * @param wordList the words that may be used as part of the transformation sequence
 * @param wordListSize the size of the word list
 * 
 * @return The length of the shortest transformation sequence from beginWord to endWord.
 */
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {

    int endWordIndex = -1; // 
    int wordSize = strnlen(beginWord, MAX_WORD_LENGTH); // 

    // look for endWord in the given word list
    for (int i = 0; i < wordListSize; i++)
    {
        if (strncmp(wordList[i], endWord, MAX_WORD_LENGTH) == 0)
        {
            endWordIndex = i;
        }
    }

    if (endWordIndex < 0) // if endWord was not found, no valid transformation sequence exists
    {
        return 0;
    }

    // initialize an array to keep track of which words in wordList have been visited during the BFS
    int* visited = malloc(wordListSize * sizeof(int));
    for (int i = 0; i < wordListSize; i++)
    {
        visited[i] = 0;
    }

    // initialize a queue that will be used to perform a BFS on the given word list
    struct Queue* q = malloc(sizeof(struct Queue));
    q->nodes = malloc((wordListSize + 1) * sizeof(struct QueueNode));
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    enqueue(q, beginWord, 1);

    while (q->size)
    {

        struct QueueNode poppedNode = dequeue(q);

        char* poppedWord = poppedNode.word;
        int poppedLevel = poppedNode.level;

        // compare the popped word to other words in wordList
        for (int i = 0; i < wordListSize; i++)
        {

            char* currentWord = wordList[i];

            if (diff(poppedWord, currentWord, wordSize) && !visited[i])
            {

                if (strncmp(currentWord, endWord, MAX_WORD_LENGTH) == 0) // if the endWord was found
                {

                    // free allocated memory
                    free(visited);
                    free(q->nodes);
                    free(q);

                    return poppedLevel + 1;

                }

                // add the adjacent word to the queue
                enqueue(q, currentWord, poppedLevel+1);
                visited[i] = 1;

            }

        }

    }

    // free allocated memory
    free(visited);
    free(q->nodes);
    free(q);

    return 0;

}



int main() {

    char* beginWord = "hit";
    char* endWord = "cog";
    char* wordList[] = {"hot","dot","dog","lot","log","cog"};
    int wordListSize = 6;

    int output = ladderLength(beginWord, endWord, wordList, wordListSize);

    printf("Output: %d\n", output);

    beginWord = "hit";
    endWord = "cog";
    char* newWordList[] = {"hot","dot","tog","cog"};
    int newWordListSize = 4;

    output = ladderLength(beginWord, endWord, newWordList, newWordListSize);

    printf("Output2: %d\n", output);

    return 0;

}