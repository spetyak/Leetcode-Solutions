
/*
 * Author: spetyak
 *
 * Runtime: Beats 100% of C submissions
 * Memory: Beats 43.77% of C submissions
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Given an array of children and their respective ratings, allocates the minimum number of candies
 * needed to give all children at least one piece of candy while giving children with
 * higher ratings than their immediate neighbors more candy than their neighbors.
 *
 * @param ratings the array of children's ratings to be used to allocate candy appropriately
 * @param ratingsSize the number of children being given candy
 * 
 * @return Returns the minimum number of candies you need to appropriately distribute candies to the children.
 */
int candy(int* ratings, int ratingsSize) {

    // initialize all kids to have 1 candy
    int* kids = malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; i++)
    {
        kids[i] = 1;
    }

    // work from left to right
    for (int i = 0; i < ratingsSize-1; i++)
    {

        // if the kid to the right of the current kid has a higher rating,
        // give the neighbor kid one more candy than the current kid
        if (ratings[i+1] > ratings[i]) 
        {
            kids[i+1] = kids[i] + 1;
        }

    }

    // work from right to left
    for (int i = ratingsSize-1; i > 0; i--)
    {

        // if the kid to the left of the current kid has a higher rating,
        // give the neighbor kid one more candy than the current kid
        if (ratings[i-1] > ratings[i] && kids[i-1] <= kids[i])
        {
            kids[i-1] = kids[i] + 1;
        }

    }

    int candies = 0; // the sum of all candies given, which should be the minimum needed

    // sum up all of the allocated candies
    for (int i = 0; i < ratingsSize; i++)
    {
        candies += kids[i];
    }

    free(kids); // free the children!

    return candies;
    
}

int main() {

    int ratings[] = {1, 0, 2};
    int ratingsSize = 3;

    printf("Output: %d\n", candy(ratings, ratingsSize));

    return 0;

}