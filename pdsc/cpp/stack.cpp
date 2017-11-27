#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "stack.h"

#define DEFAULT_SIZE 100
#define DOUBLE_SIZE 2

Stack::Stack(unsigned int sizeIncrement) {
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
Stack::Stack() {
	top = 0;
	size = DEFAULT_SIZE;
	data = (int*)malloc(size  * sizeof(int));
	if (data == NULL) {
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
}
Stack::~Stack() {}
void Stack::clear() {
	free(data);
}
bool Stack::isEmpty() {
	return top == 0;
}
void Stack::push(int element) {
	if(!this){
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
		return;
	}
	if(top == size && top != 0) {
		size *= DOUBLE_SIZE;
		int* temp = NULL;
		temp = (int*)realloc(data, size * sizeof(int));
		printf("realloc of %d bytes performed\n",size * sizeof(int));
		if (temp == NULL) {
			printf("push error\nstack back to previous state\n");
			perror("realloc fail");
			exit(EXIT_FAILURE);
		}
		data = temp;
	}
	data[top] = element;
	top++;
	printf("push performed\n");
}
int Stack::pop() {
	int element = 0;
	if(this != NULL)
	{
		if(!this->isEmpty()) {
			printf("pop performed\n");
			element = data[top-1];
			printf("%d\n",element);
			top--;
			return element;
		}
		else {
			printf("stack isEmpty\n");
			this->clear();
			exit(EXIT_FAILURE);
		}
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}