
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Author: spetyak
 *
 * Runtime: Beats --.--% of C submissions
 * Memory: Beats --.--% of C submissions
 */

#define MAX_WORD_LENGTH 10

struct myNode {
    int val;
    struct myList* next;
};

struct myList {
    int size;
    struct myNode* head;
    struct myNode* tail;
};

struct myQueue {
    int size;
    struct myList* head;
    struct myList* tail; 
};

int diff(char* a, char* b, int stringSize) {

    int difference = 0;

    for (int i = 0; i < stringSize; i++)
    {
        if (a[i] != b[i])
        {
            difference++;
        }
    }

    return difference == 1;

}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    
    int shortestSequenceLength = 0;
    int endWordIndex = -1;
    int beginWordIndex = -1;
    int wordSize = strnlen(beginWord, MAX_WORD_LENGTH);

    for (int i = 0; i < wordListSize; i++)
    {
        if (strncmp(wordList[i], endWord, MAX_WORD_LENGTH) == 0)
        {
            endWordIndex = i;
        }

        if (strncmp(wordList[i], beginWord, MAX_WORD_LENGTH) == 0)
        {
            beginWordIndex = i;
        }

    }

    if (endWordIndex < 0)
    {
        return 0;
    }

    if (beginWordIndex < 0)
    {

        beginWordIndex = 0;
        wordListSize++;
        char** updatedWordList = malloc((wordListSize) * sizeof(char*));
        updatedWordList[0] = beginWord;
        for (int i = 1; i < wordListSize; i++)
        {
            updatedWordList[i] = wordList[i-1];
        }

        free(wordList);

        wordList = updatedWordList;

    }

    int* visited = malloc(wordListSize * sizeof(int));

    int** wordMatrix = malloc(wordListSize * sizeof(int*));
    for (int i = 0; i < wordListSize; i++)
    {
        wordMatrix[i] = malloc(wordListSize * sizeof(int));
    }

    for (int i = 0; i < wordListSize; i++)
    {
        
        char* word = wordList[i];

        for (int j = i; j < wordListSize; j++)
        {
            int difference = diff(word, wordList[j], wordSize);
            wordMatrix[i][j] = difference;
            wordMatrix[j][i] = difference;
        }
        
    }

    printf("Word Matrix:\n");
    for (int i = 0; i < wordListSize; i++)
    {
        for (int j = 0; j < wordListSize; j++)
        {
            printf("%d ", wordMatrix[i][j]);
        }
        printf("\n");
    }

    // all you need now is a list and a queue of lists

    struct myQueue* queue = malloc(sizeof(struct myQueue));
    
    struct myList* pushList = malloc(sizeof(struct myList));

    struct myNode* newNode = malloc(sizeof(struct myNode));
    newNode->val = beginWordIndex;
    newNode->next = NULL;

    pushList->head = newNode;
    pushList->tail = pushList->head;
    pushList->size = 1;

    queue->head = pushList;
    queue->tail = queue->head;
    queue->size = 1;

    while (queue->size > 0)
    {

        // grab the next list of level nodes from the head of the queue
        // create a new push list

        // loop through values in the popped level list
        //  L grab each word in the popped list
        //  L loop through that words connections to other words in wordList
        //      L checkif the current connection differs by 1, the new word is not already in the level list, 
        //        and the new word has not been visited yet
        //          L if the current wordList word equals the endWord, flag to stop working with the queue
        //          L if the currentWord has not been visited yet, add it to the push list
        
        // mark all words at this level as visited to avoid cycles in the graph

        // if the endWord was flagged, break from the queue loop
        // otherwise, if the push list is not empty, add the push list to the queue

        // free levelList

    }

    return shortestSequenceLength;

}



int main() {

    

    return 0;

}