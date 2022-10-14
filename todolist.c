/* todolist.c
 *
 * This program keeps track of tasks that need to be completed and allows us to 
 * add, list, or delete the tasks. A task is a structure that contains an id 
 * number, a string for the label (40 characters, null terminated), and a priority
 * value (1 - top, 2 - important, 3 - other).
 * 
 * Prof. Frank Emanuel, Ph.D. 
 * CST8234
 * 2022-10-13
 */

#include <stdio.h>

struct todoitem
{
    /* A task has an id number, a label (string), and a priority level (1-3) */

    int task_id;
    int priority_level;
    char task_label[40];

};

void printlistitems( struct todoitem * items, int item_count ){

    /* prints all of the list */

    int item_offset = 0;

    for ( ;item_count > 0; item_count--, item_offset++){
        printf("%d: %s (%d)\n", 
            items[item_offset].task_id, items[item_offset].task_label, 
            items[item_offset].priority_level);
    }

    return;
}

int main(){

    /* declarations - replace test array with a dynamic array */
    
    struct todoitem single_task[] = { {1, 1, "hello"}, {2, 1, "goodbye"}, {3, 3, "ok"} };
    
    /* instructions */

    printf("Let's get stuff done!\n\n");

    printlistitems( single_task, 3 );
    
    return 0;
}


