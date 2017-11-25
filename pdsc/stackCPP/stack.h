#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define DEFAULT_SIZE 100
#define DOUBLE_SIZE 2
#define EMPTY_STACK -1
#define STACK_NOT_INITED -2

class Stack
{
	public:
		void push(int element);
		int pop();
		void clear();
		bool isEmpty();
		Stack(unsigned int sizeIncrement);
		Stack();
		~Stack();
		int getTop();
	private:
		int top;
		int* data;
		int size;
		int sizeIncrement;
};
