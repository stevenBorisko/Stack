#include "Stack.h"

//----------------------------------------------------------------------------//
// --- Stack Function Implementation ---
//----------------------------------------------------------------------------//

Stack Stack_init() {
	Stack ret;
	ret.head = NULL;
	ret.count = 0;
	return ret;
}

void Stack_push(Stack* stack, void* data) {
	struct StackNode* newHead = malloc(sizeof(struct StackNode));

	newHead->data = data;
	newHead->next = stack->head;
	stack->head = newHead;

	++(stack->count);
}

void* Stack_pop(Stack* stack) {
	struct StackNode* headNext = stack->head->next;
	void* ret = stack->head->data;

	free(stack->head);
	stack->head = headNext;

	--(stack->count);

	return ret;
}

void* Stack_peek(const Stack* stack) {
	return stack->head->data;
}

int Stack_isEmpty(const Stack* stack) {
	return !(stack->head);
}

unsigned int Stack_count(const Stack* stack) {
	return stack->count;
}

void Stack_clear(Stack* stack, void (*destroy)(void*)) {
	struct StackNode* headNext;
	while(stack->head) {
		// destroy the data inside the head node
		if(stack->head->data) (*destroy)(stack->head->data);
		// frr the head node and set it to the next node
		headNext = stack->head->next;
		free(stack->head);
		stack->head = headNext;
	}

	// reset count
	stack->count = 0;
}
