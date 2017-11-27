#include <stdbool.h>

typedef struct stack
{
	int top;
	int* array;
	int size;
}stack;

void init(stack* s, unsigned int sizeOfIncrement);
void destroy(stack* s);
void push(stack* s, int element);
int pop(stack* s);
bool isEmpty(stack* s);