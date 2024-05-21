#include "hash_table.h"

void hash_create(Hash_table_t *arr, int size)
{
    for(int i = 0; i < size; i++) {
        arr[i].idx = i;
        arr[i].val = -1;
        arr[i].node = NULL;
    }
}
int hash_insert(Hash_table_t *arr, int size, int data)
{
    int hash_idx = data%size;
    if(arr[hash_idx].val == -1) {
        arr[hash_idx].val = data;
        return 0;
    }
    Hash_table_t *new = malloc(sizeof(Hash_table_t));
    new->idx = hash_idx;
    new->val = data;
    new->node = NULL;
    if(arr[hash_idx].node == NULL) {
        arr[hash_idx].node = new;
        return 0;
    }
    Hash_table_t *temp = malloc(sizeof(Hash_table_t *));
    temp = arr[hash_idx].node;
    while(temp->node !=NULL) {
        temp = temp->node;
    }
    temp->node = new;
    return 0;
}
int hash_search(Hash_table_t *arr,int size, int data)
{
  //  printf("test_!\n");
    int hash_idx = data%size;
    if(arr[hash_idx].val != data && arr[hash_idx].node == NULL) {
        printf("data not found\n");
        return DATA_NOT_FOUND;
    }
   // printf("test");
    if(arr[hash_idx].val == data) {
        return DATA_FOUND;
    }
    Hash_table_t *temp = malloc(sizeof(Hash_table_t *));
    temp = arr[hash_idx].node;
    while(temp != NULL) {
        if(temp->val == data) {
            return DATA_FOUND;
        } else {
            temp = temp->node;
        }

    }
    return DATA_NOT_FOUND;
}

void hash_display(Hash_table_t *arr, int size)
{
    Hash_table_t *temp = malloc(sizeof(Hash_table_t*));
    temp = arr;
    for(int i=0;i<size;i++){
        if(arr[i].val != -1) {
            printf("%d\t",arr[i].val);
        }
        if(arr[i].node != NULL) {
            temp = arr[i].node;
            while(temp !=NULL) {
                printf("%d\t",temp->val);
                temp = temp->node;
            }
            printf("\n");
        }

    }
    printf("\n");

}
