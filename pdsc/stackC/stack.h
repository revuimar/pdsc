#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

#define DEFAULT_SIZE 100
#define DOUBLE_SIZE 2

typedef struct stack
{
	int top;
	int sizeIncrement;
	int* array;
	int size;
}stack;

void init(stack* s, unsigned int sizeOfIncrement);
void destroy(stack* s);
void push(stack* s, int element);
int pop(stack* s);
bool isEmpty(stack* s);