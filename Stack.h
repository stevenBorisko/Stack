#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

//----------------------------------------------------------------------------//
// --- Structure Declarations ---
//----------------------------------------------------------------------------//

/*
--- struct StackNode ---

data (void*)
	- The data stored in the stack
next (struct StackNode*)
	- One node closer to the bottom of the stack

Wrapper struct for storing data in a Stack
*/
struct StackNode {
	void* data;
	struct StackNode* next;
};

/*
--- struct Stack ---

head (struct StackNode*)
	- Top of the stack,
	- I.e. the next element to be popped,
	- I.e. the last element that was pushed
count (unsigned int)
	- The number of elements in the stack

LIFO data structure. Functions found below
*/
typedef struct {
	struct StackNode* head;
	unsigned int count;
}Stack;

//----------------------------------------------------------------------------//
// --- Stack Function Declarations ---
//----------------------------------------------------------------------------//

/*
--- Stack_init ---

return (Stack)
	Initialized Stack

Creates a Stack and initializes it to an empty Stack
*/
Stack Stack_init();

/*
--- Stack_create ---

return (Stack*)
	Malloc'ed and initialized Stack

Allocates space for and initializes a Stack
*/
Stack* Stack_create();

/*
--- Stack_push ---

stack (Stack*)
	- Stack to which p:data will be pushed
data (void*)
	- Data to be pushed onto p:stack

Adds a new element to the top of the stack
*/
void Stack_push(Stack* stack, void* data);

/*
--- Stack_pop ---

stack (Stack*)
	- stack from which the return value will be popped

return (void*)
	Data popped from p:stack

Removes the top element from the stack and returns it
*/
void* Stack_pop(Stack* stack);

/*
--- Stack_peek ---

stack (const Stack*)
	- Stack to be inspected

return (void*)
	The next element to be popped and the last element that was pushed

Returns the top of the stack
	- Shallow copy
*/
void* Stack_peek(const Stack* stack);

/*
--- Stack_isEmpty ---

stack (const Stack*)
	- stack to be inspected

return (int)
	Whether the p:queue contains any elements

Returns whether the stack is empty
*/
int Stack_isEmpty(const Stack* stack);

/*
--- Stack_count ---

stack (const Stack*)
	- Stack to be inspected

return (unsigned int)
	Count of all the elements in p:stack

Returns the number of elements in the stack
*/
unsigned int Stack_count(const Stack* stack);

/*
--- Stack_clear ---

stack (Stack*)
	- Stack to be cleared
destroy	(void (void*))
	- Function that handles the freeing of v:data in each element of p:stack

Empties the stack
*/
void Stack_clear(Stack* stack, void (*destroy)(void*));

#endif
