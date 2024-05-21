
#include "hash_table.h"

int main()
{
    int op;
    int data,ret;
    int size = 10;
    Hash_table_t arr[10];
    hash_create(arr, size);
    while(1) {
        printf("1. Insert data in HT\n2. Search data in HT\n3. Delete data from HT\n4. Destroy HT\n5. Display HT\n6. Exit\nEnter you choice : ");
        scanf("%d",&op);
        switch(op) {
            case 1:
                printf("enter the value\n");
                scanf("%d",&data);
                hash_insert(arr, size, data);
                break;
            case 2:
                printf("enter the data to search\n");
                scanf("%d",&data);
                ret = hash_search(arr,size, data);
                if( ret == DATA_FOUND) {
                    printf("data presemt\n");
                } else {
                    printf("data not found\n");
                }
                break;
            case 5:
                    hash_display(arr, size);
                    break;

        }

    }
    return 0;   

}
