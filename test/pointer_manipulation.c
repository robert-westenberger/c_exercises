#include <stdio.h>
#include <inttypes.h>

/* pointers and arrays */
int main() {
    const int CAPACITY = 5;
    int a[5] = { 22, 35, 12, 21, 33 };

    for (int i = 0; i < CAPACITY; i++) {
        printf("%d %d \n", a[i], *(a+i));
    }
    return 0;
}

/* pointer to pointer */ 
int pointer_to_pointer_example() {
    int a = 1025;
    int *p = &a;
    int **q = &p;
    int ***r = &q;
    ***r = 10;
    printf("size of integer is %lu \n", sizeof(int));
    printf("Address = %p \n value = %d \n", p, **q);
    

    return 0;
}

/* void / generic pointer example */ 
int void_generic_example() {
    int a = 1025;
    int *p = &a;
    printf("size of integer is %lu \n", sizeof(int));
    printf("Address = %p \n value = %d \n", p, *p);
    // we cannot dereference a void pointer
    void *p0;
    p0 = p;
    printf("Address = %p", p0 );
    return 0;
}
int typecasting_example() {
    int a = 1025;
    int *p = &a;
    printf("size of integer is %lu \n", sizeof(int));
    printf("Address = %p \n value = %d \n", p, *p);
    printf("Address = %p \n value = %d \n", p+1, *(p+1));
    char *p0;
    p0 = (char*)p; // typecasting
    printf("size of integer is %lu \n", sizeof(int));
    printf("Address = %p \n value = %d \n", p0, *p0);
    printf("Address = %p \n value = %d \n", p0, *(p0+1));
    return 0;
}