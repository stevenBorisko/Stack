#ifndef STACK_H
#define STACK_H

/*
var	data	(void*)
	the data stored in the stack
var	next	(struct StackNode*)
	one node closer to the bottom of the stack

Wrapper struct for storing data in a Stack
*/
struct StackNode {
	void* data;
	struct StackNode* next;
};

/*
var	head	(struct StackNode*)
	top of the stack,
	i.e. the next element to be popped,
	i.e. the last element that was pushed
var	count	(unsigned int)
	the number of elements in the stack

LIFO data structure. Functions found below
*/
typedef struct {
	struct StackNode* head;
	unsigned int count;
}Stack;

/*
return		(Stack)
	initialized Stack

Creastes a Stack and initializes it to an empty Stack
*/
Stack Stack_init()l

/*
return		(Stack*)
	malloc'ed and initialized Stack

Allocates space for and initializes a Stack
*/
Stack* Stack_create();

/*
param	stack	(Stack*)
	stack to which p:data will be pushed
param	data	(void*)
	data to be pushed onto p:stack
return		(void)

Adds a new element to the top of the stack
*/
void Stack_push(Stack* stack, void* data);

/*
param	stack	(Stack*)
	stack from which the return value will be popped
return		(void*)
	data popped from p:stack

Removes the top element from the stack and returns it
*/
void* Stack_pop(Stack* stack);

/*
param	stack	(const Stack*)
	stack to be inspected
returns		(void*)
	the next element to be popped and the last element that was pushed

Returns the top of the stack
*/
void* Stack_peek(const Stack* stack);

/*
param	stack	(const Stack*)
	stack to be inspected
return		(int)
	whether the p:queue contains any elements

Returns whether the stack is empty
*/
int Stack_isEmpty(const Stack* stack);

/*
param	stack	(const Stack*)
	stack to be inspected
return		(unsigned int)
	count of all the elements in p:stack

Returns the number of elements in the stack
*/
unsigned int Stack_count(const Stack* stack);

/*
param	stack	(Stack*)
	stack to be cleared
param	destroy	(void (void*))
	function that handles the freeing of v:data in each element of p:stack
return		(void)

Empties the stack
*/
void Stack_clear(Stack* stack, void (*destroy)(void*));

#endif
