#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


/*

Given a string s, find the length of the longest substring without 
repeating characters.

*/

int lengthOfLongestSubstring(char * s){
    /* 128 = max val of ASCII characters */
    int counts[128] = {0};
    int result = 0;
    char* start = s;
    char* end = s;
    /* While loop begins with both start and and (the window) to the first item in the string*/
    while (*end) {
        if (counts[*end]) {
            result = (end - start > result) ? end - start : result;
            while (*start != *end) {
                counts[*start] = 0;
                start++;
            }
            start++;
            end++;
        }
        else {
            counts[*end] = 1;
            end++;
        }  
    }
    return end-start > result ? end-start : result;
}

int main()
{   
    char s1[] = "pwwkew";

    // char s2[] = "bbbbb";
    // char s3[] = "pwwkew";
    lengthOfLongestSubstring(s1);
    // lengthOfLongestSubstring(s2);
    // lengthOfLongestSubstring(s3);
    printf("%s %d \n", s1, lengthOfLongestSubstring(s1));
    // printf("%s %d \n", s2, lengthOfLongestSubstring(s2));
    // printf("%s %d \n", s3, lengthOfLongestSubstring(s3));
    return 0;

}