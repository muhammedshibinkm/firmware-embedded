#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<stdio.h>
#include<stdlib.h>

#define DATA_NOT_FOUND 1
#define DATA_FOUND 2

typedef struct Hash_table
{
    int idx;
    int val;
    struct Hash_table *node;
}Hash_table_t;

void hash_create(Hash_table_t*, int);
int hash_insert(Hash_table_t*, int, int);
int hash_search(Hash_table_t*,int, int);
void hash_display(Hash_table_t *, int );


#endif //HASH_TABLE_H
