#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "map.h"

/*

Given a string s, find the length of the longest substring without repeating 
characters.

*/

int maxVal(a, b) {
    return a >= b ? a : b;
}
int lengthOfLongestSubstring(char * s){
    return 1;
    // int leftWindow = 0;
    // int longest = 0;
    // const char *key;
    // map_int_t counts;
    // map_init(&counts);
    // /* The sliding window portion of the algorithm. */
    // /* Note that the for loop doesn't automatically increment. */
    // for (int rightWindow = 0; rightWindow < strlen(s);) {
    //     char rightWindowItem = s[rightWindow];
    //     /* If the current character at the rightWindow index doesn't exist,
    //     put it in the counts map as 0 */
    //     if (map_get(&counts, &rightWindowItem) == NULL) {
    //         printf("Adding %s to counts \n", &rightWindowItem);
    //         map_set(&counts, &rightWindowItem, 0);
    //     }
    //     /* Increment the current character at rightwindow  */
    //     map_set(&counts, &rightWindowItem, *map_get(&counts, &rightWindowItem ) + 1);
        
    //     /* Check to see whether we have encountered a character before by 
    //     checking counts hash map for a key with a value > 1. 
    //     If we do have a duplicate, we need to
    //     1. Decrement the character at leftWindow, contracting the window. 
    //     2. Increment leftWindow to see if the next substring will be longer
    //     than the previous starting at leftWindow and ending at rightWindow. */
    //     map_iter_t iter = map_iter(&counts);
    //     char leftWindowItem = s[leftWindow];
    //     while ((key = map_next(&counts, &iter))) {
    //         // printf("key: %s value: %d \n", key, *map_get(&counts, key));
    //         if (*map_get(&counts, key) > 1) {
    //             map_set(&counts, &leftWindowItem, *map_get(&counts, &leftWindowItem ) - 1);
    //             leftWindow += 1;
    //             // continue;
    //         }
    //     }
    //     /* Update longest value with the current substrings length */
    //     longest = maxVal(longest, rightWindow - leftWindow + 1);
    //     /* Expand the window */
    //     rightWindow += 1;
    //     printf("\n");
    // }
    // return longest;
}

int main()
{   
    char s1[] = "pwwkew";
    // char s2[] = "bbbbb";
    // char s3[] = "pwwkew";
    lengthOfLongestSubstring(s1);
    // lengthOfLongestSubstring(s2);
    // lengthOfLongestSubstring(s3);
    // printf("%s %d \n", s1, lengthOfLongestSubstring(s1));
    // printf("%s %d \n", s2, lengthOfLongestSubstring(s2));
    // printf("%s %d \n", s3, lengthOfLongestSubstring(s3));
    return 0;

}