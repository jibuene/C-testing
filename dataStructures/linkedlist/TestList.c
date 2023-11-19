#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    struct LinkedList *list = create_randomised_list(50);
    printf("List length: %d \n", list->length);
    print_all_nodes(list);
    printf("Searching for 5. Is it in list: %d", linear_search(list, 5));
    return 0;
}
