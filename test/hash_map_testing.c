#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "string_helpers.h"
#include "map.h"





int main()
{   
    char s1[] = "pwwkew";
    MapNode *hashMap[HASHSIZE] = { NULL };
    char s2[] = "";
   
    substring(s2, &s1[1], 1);
    
    set_HashMap(hashMap, s2, 1);
    printf("%d \n", (get_HashMap(hashMap, s2))->value);
    substring(s2, &s1[2], 1);
    set_HashMap(hashMap, s2, 2);
    printf("%d \n", (get_HashMap(hashMap, s2))->value);
    
    
    return 0;

}