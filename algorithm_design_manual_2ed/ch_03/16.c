#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "singly_linked_list.h"
#include "uthash.h"

/* WIP */
struct hash_struct
{
    int id;
    int index;
    UT_hash_handle hh;
};

void read_words(FILE *f)
{
    char x[1024];
    /* assumes no word exceeds length of 1023 */
    while (fscanf(f, " %1023s", x) == 1)
    {
        printf("PRocessing %s \n", x);
        // if (!contains_SinglyLinkedList(wordList, x)) {
        //   insert_SinglyLinkedList(wordList, x);
        // }
    }
}

int main()
{
    // SinglyLinkedList *wordList = create_SinglyLinkedList(data_ops_string);
    FILE *fp;
    fp = fopen("./data/small.txt", "r"); //read only
    // read_words(fp, wordList);
    // print_SinglyLinkedList(wordList, string_print);
    // printf("%d\n", sizeof_SinglyLinkedList(wordList));
    // SinglyLinkedList *test = create_SinglyLinkedList(data_ops_string);
    // insert_SinglyLinkedList(test, "Hello 1");
    // insert_SinglyLinkedList(test, "Hello 2");
    // insert_SinglyLinkedList(test, "Hello 3");
    // insert_SinglyLinkedList(test, "Hello 4");
    // deleteValue_SinglyLinkedList(test, "Hello 33");
    // print_SinglyLinkedList(test, string_print);

    return 0;
}