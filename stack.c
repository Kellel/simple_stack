/*
 * Project: Simple stack implementation
 * Author: Kellen Fox
 * Date: May 24, 2015
 * Description:
 *         Toy implementation of a stack. Just to work on my C chops. Make sure I
 *    can still allocate things and remember how pointers work. I chose to do a
 *    stack because you only have to keep track of the head. EZ
 */
#include <stdlib.h>
#include "stack.h"

/* Internal Node Representation */
struct _Node {
    void *data;
    Node *next;
};

/* Internal Stack Representation */
struct _Stack {
    Node *first;
    int length;
};

/* Create a stack */
Stack *stack_new() {
    Stack *stack = malloc(sizeof(Stack));
    stack->length = 0;
    stack->first = NULL;
    return stack;
}

/* Cleanup a stack */
STATUSCODE stack_destroy(Stack *stack)
{
    if (stack->length > 0) {
        return NOTEMPTY;
    }

    free(stack);
    return SUCCESS;
}

/* Push an item onto the stack */
STATUSCODE stack_push(Stack *stack, void *item)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = stack->first;
    stack->first = tmp;
    ++stack->length;
    return SUCCESS;
}

/* Pop an item off the stack */
void *stack_pop(Stack *stack)
{
    if (stack->length < 1) {
        return NULL;
    }

    Node *tmp = stack->first;

    if (tmp != NULL) {
        stack->first = tmp->next;
        void *data = tmp->data;
        stack->length--;
        return data;
    } else {
        return NULL;
    }
}

/* recursively get the length of a node */
int rec_node_length(Node *node)
{
    if (node->next != NULL){
        return rec_node_length(node->next) + 1;
    } else {
        return 1;
    }
}

/* Alternate length function */
int rec_stack_length(Stack *stack)
{
    return rec_node_length(stack->first);
}

/* Get the length of a stack */
int stack_length(Stack *stack)
{
    int rec_len = rec_node_length(stack->first);
    if (rec_len != stack->length){
        return SIZEERROR;
    }
    return stack->length;
}

