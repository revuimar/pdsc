//stack.cpp
#include "stack.h"
Stack::Stack(unsigned int sizeIncrement)
{
	top = 0;
	size = DEFAULT_SIZE * sizeIncrement;
	if(size == 0) {
		printf("stack size can't be 0\ninitialisation failed\n");
		exit(EXIT_FAILURE);
	}
	data = (int*)malloc(size * sizeof(int));
	if (data == NULL) {
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
}
Stack::Stack()
{
	top = 0;
	size = DEFAULT_SIZE;
	sizeIncrement = 1;
	data = (int*)malloc(size  * sizeof(int));
	if (data == NULL) {
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
}
Stack::~Stack(){}
void Stack::clear()
{
	free(data);
}
bool Stack::isEmpty()
{
	return top == 0;
}
void Stack::push(int element)
{
	if(!this){
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
		return;
	}
	if(top == size && top != 0) {
		size += size;
		int* temp = NULL;
		temp = (int*)realloc(data, size * sizeof(int));
		printf("realloc of %ld bytes performed\n",size * sizeof(int));
		if (temp == NULL) {
			printf("push error\nstack back to previous state\n");
			size /= DOUBLE_SIZE;
			perror("realloc fail");
			exit(EXIT_FAILURE);
		}
		data = temp;
	}
	data[top] = element;
	top++;
	printf("push performed\n");
}
int Stack::pop()
{
	int element=0;
	if(this != NULL)
	{
		if(!this->isEmpty())
		{
			printf("pop performed\n");
			element = data[top-1];
			printf("%d\n",element);
			top--;
			return element;
		}
		else
		{
			printf("stack isEmpty\n");
			this->clear();
			exit(EXIT_FAILURE);
		}
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}
int Stack::getTop()
{
	return top;
}
int main()
{
	Stack test = Stack();
	printf("###############initialisation standard size############\n");
	for(int i=0; i<1000; i++)
	{
		test.push(i);
		printf("pushed %d value to %d\n", i, test.getTop());
	}
	for(int i=0; i<1000; i++)
	{
		printf("%d\n",test.pop());
	}
	test.clear();
	return 0;
}