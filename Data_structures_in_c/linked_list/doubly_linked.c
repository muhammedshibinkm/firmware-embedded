#include<stdio.h>
#include<stdlib.h>

typedef struct double_list
{
    int data;
    struct double_list *next;
    struct double_list *prev;
}Node;
Node * create_node(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insert_atEnd(Node **head, int data)
{
    Node *new_node = create_node(data);
    if( *head == NULL ) {
        *head = new_node;
    }
    Node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
insert_at_first(Node **head, int data)
{
    Node *node = create_node(data);
    node->next = *head;
    if(*head != NULL) {
        (*head)->prev = node;
    }
    *head = node;
}


int main()
{
    Node *head = NULL;
    insert_atEnd(&head, 10);
}
