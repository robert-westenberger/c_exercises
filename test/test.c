#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

#define HASHSIZE 101


/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(struct nlist *hashtab[HASHSIZE], char *s)
{
    struct nlist *np;
    
    int test1 = hash(s);
    struct nlist *test2 = hashtab[test1];
    struct nlist *test3 = *(hashtab + test1);
    // printf("test 2: %p \n", test2);
    for (np = test2; np != NULL; np = np->next)
        // printf("test %s %s \n ", np->name, np->defn);
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}


/* install: put (name, defn) in hashtab */
struct nlist *install(struct nlist *hashtab[HASHSIZE], char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(hashtab, name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

struct nlist *install2(struct nlist *hashtab[HASHSIZE], char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    
    return np;
}

int main()
{   
    struct nlist* hashtab[HASHSIZE] = { NULL };
    struct nlist* hashtab2[HASHSIZE];
    __asm("NOP");
    install(hashtab, "test", "hey");
    // install(hashtab, "test", "hey");
    // lookup(hashtab, "test");
    return 0;
}