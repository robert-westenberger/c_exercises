#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "map.h"

int main()
{   
    char s1[] = "pwwkew";
    MapNode *hashMap[HASHSIZE] = { NULL };
    
    set_HashMap(hashMap, "test", 5);
    
    printf("%d \n", (get_HashMap(hashMap, "test"))->value);
    return 0;

}