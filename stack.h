/*
 * Project: Simple stack implementation
 * Author: Kellen Fox
 * Date: May 24, 2015
 * Description:
 *         Toy implementation of a stack. Just to work on my C chops. Make sure I
 *    can still allocate things and remember how pointers work. I chose to do a
 *    stack because you only have to keep track of the head. EZ
 */

/* Status Codes
 *
 * Returned from any function that can have an error
 */
typedef enum {SUCCESS, NOTEMPTY, SIZEERROR} STATUSCODE;

/* Basic Node type */
typedef struct _Node Node;

/* Basic Stack type */
typedef struct _Stack Stack;

/* Create a stack object */
Stack *stack_new();

/* Destroy a stack object */
STATUSCODE stack_destroy(Stack *stack);

/* Push an item on the stack */
STATUSCODE stack_push(Stack *stack, void *item);

/* Pop an Item off the stack */
void *stack_pop(Stack *stack);

/* Get the length of the stack */
int stack_length(Stack *stack);

/* Alternate stack length function */
int rec_stack_length(Stack *stack);
