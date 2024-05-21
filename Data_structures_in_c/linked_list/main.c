#include "linked_list.h"


int main()
{
    Node *head = NULL;
    insert_first(&head, 5);
    insert_end(&head, 10);
    insert_end(&head, 15);
    insert_end(&head, 20);
    insert_first(&head, 25);
    print_list(&head);
    delete_data(&head, 10);
    print_list(&head);
    reverse_list(&head);
    print_list(&head);
    search_data(&head, 15);
    middle_element_optimised(head);
   // make_it_as_cycle(&head);
    if(find_cycle(head))
    {
        printf("it's cyclic\n");
    }
    else {
        printf("it's not cyclic\n");
    }
    find_kth_node_from_last(&head, 3);
    find_kth_node_from_last_optimised(&head, 3);

    return 0;

}
