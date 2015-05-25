#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char ** argv)
{

    // Create a play stack for some numbers
    Stack *stack = stack_new();

    // put the numbers from 0 to 124 in the stack
    for(int i=0; i<125; i++){
        int *item = malloc(sizeof(int));
        *item=i;
        STATUSCODE status = stack_push(stack, item);
        if (status != SUCCESS){
            printf("ERROR ADDING ITEM\n");
        }
    }

    // Get the length
    int length = stack_length(stack);

    // For printing
    int row_width = 8;

    // Put some fun data here
    Stack *mods = stack_new();

    for(int i=1; i<=length; i++){
        int *data = stack_pop(stack);
        if (i % row_width > 0){
            printf("%-8i", *data);
        } else {
            printf("%-8i\n", *data);
        }
        // Do something strange with data just because
        *data = *data ^ 0x00010;
        stack_push(mods, data);
    }

    printf("\n");
    printf("\n");

    // print the contents and remove the items
    for(int i=1; i<=length; i++){
        int *data = stack_pop(mods);
        if (i % row_width > 0){
            printf("%-8i", *data);
        } else {
            printf("%-8i\n", *data);
        }
        free(data);
    }

    printf("\n");

    // Cleanup the stacks
    STATUSCODE status = stack_destroy(stack);
    STATUSCODE status_m = stack_destroy(mods);
    printf("EXITCODE: %i\n", status + status_m);
}
