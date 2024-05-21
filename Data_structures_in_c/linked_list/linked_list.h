
#ifndef LINKED_LIST_H
#define  LINKED_LIST_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

typedef struct Arr
{
    int count;
    Node *node_address[100];
}Node_Arr;
Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL) {
        perror("malloc_failed\n");
        exit(0);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;


}

void insert_first(Node **head, int data)
{
    Node *node = create_node(data);
    node->link = *head;
    *head= node;
    return;
}
void insert_end(Node **head, int data)
{
    Node *node = create_node(data);
    if(*head == NULL){
        *head = node;
        return;
    }
    Node *temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = node;
    return;
}

int search_data(Node **head, int data)
{
    Node *temp  = *head;
    while(temp !=NULL)
    {
        if(temp->data == data)
        {
            printf("data[%d] found",data);
            return 0;
        }
        temp = temp->link;
    }
    printf("data [%d] not found\n",data);
    return 0;
}
void clear_list(Node **head)
{
    Node *temp = *head;
    Node *temp1 = NULL;
    while( temp != NULL)
    {
        temp1 = temp->link;
        free(temp);
        temp = temp1;
    }
    printf("list freed succsussfully\n");
}
void reverse_list(Node **head)
{
    Node *current = *head;
    Node *prev = NULL;
    Node *next = NULL;
    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void delete_data(Node **head, int data)
{
    Node *temp = *head;
    Node *prev = NULL;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            prev->link = temp->link;
            free(temp); temp = NULL;
            printf("list of [%d] is cleared\n", data);
            break;
        }
        prev = temp;
        temp = temp->link;
    }
    return;
}

void print_list(Node **head)
{
    Node *temp = *head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
    return;
}

void middle_element(Node **head)
{
    int *arr = malloc(sizeof(int) * 100);
    Node *temp = *head;
    int i=0;
    while(temp !=NULL) {
        arr[i++] = temp->data;
        temp = temp->link;
    }
    printf("\nmiddle elemnt is [%d]\n",arr[i/2]);
}

void middle_element_optimised(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;
    }
    printf("\nmiddle element data = %d\n", slow->data);
}

int find_cycle(Node *head)
{
    //using floyd's tortise and hare, algorithm
    //using two pointers,slow and fast, slow is travese one node at a time
    //fast is traverse two node at a time.
    if(head == NULL || head->link == NULL)
        return 0;
    Node *slow = head;
    Node *fast = head->link;
    
    while(slow != fast)
    {
        if(fast == NULL || fast->link == NULL)
        {
            return 0;
        }
        slow = slow->link;
        fast = fast->link->link;
    }
    return 1;

}
void make_it_as_cycle(Node **head)
{
    Node *temp = *head;
    while(temp->link !=NULL)
    {
        temp = temp->link;
    }
    temp->link = *head;
}

void find_kth_node_from_last(Node **head, int k)
{
    Node_Arr arr;
    Node *temp = *head;
    arr.count = 0;
    while(temp != NULL)
    {
        printf("%d\n",arr.count);
        arr.count++;
        arr.node_address[arr.count] = temp;
        temp = temp->link;
    }
    if( (0 <= (arr.count - k)) && (k >= 0))
    {
        Node *temp = arr.node_address[arr.count - k];
        printf("[%d]th valus is [%d]\n",k, temp->data);
    } else {
        printf("the size of list is lessthan k, size of list is [%d]\n", arr.count);
    }
}
void find_kth_node_from_last_optimised(Node **head, int k)
{
    Node *slow = *head;
    Node *fast = *head;

    for(int i=0;i<k;i++)
    {
        fast = fast->link;
    }

    while(fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link;
    }
    printf("[%d]th link from last data is [%d]\n",k,slow->data);
    return;
}



#endif //LINKED_LIST_H
