#include "stack.h"

void init(stack* s, unsigned int sizeOfIncrement) {
	s->top = 0;
	s->sizeIncrement = sizeOfIncrement;
	s->size = sizeOfIncrement * DEFAULT_SIZE;
	if(s->size == 0) {
		printf("stack size can't be 0\ninitialisation failed\n");
		exit(EXIT_FAILURE);
	}
	s->array = malloc(s->size * sizeof(int));
	if (s->array == NULL) {
		perror("malloc fail");
		exit(EXIT_FAILURE);
	}
}

void destroy(stack* s) {
	free(s->array);
}

void push(stack* s, int element) {
	if(!s){
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
		return;
	}
	if(s->top == s->size && s->top != 0) {
		int* temp = NULL;
		s->size += s->size;
		temp = realloc(s->array, s->size * sizeof(int));
		printf("realloc of %ld bytes performed\n",s->size * sizeof(int));
		if (temp == NULL) {
			printf("push error\nstack back to previous state\n");
			s->size /= DOUBLE_SIZE;
			perror("realloc fail");
			exit(EXIT_FAILURE);
		}
		s->array = temp;
	}
	s->array[s->top] = element;
	s->top++;
	printf("push performed\n");
}

int pop(stack* s){
	int element = 0;
	if(s != NULL)
	{
		if(!isEmpty(s))
		{
			printf("pop performed\n");
			element = s->array[s->top - 1];
			printf("%d\n",element);
			s->top--;
			return element;
		}
		else
		{
			printf("stack isEmpty\n");
			destroy(s);
			exit(EXIT_FAILURE);
		}
		printf("ivalid arg\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

bool isEmpty(stack* s){
	if(s == NULL){
		return false;
	}
	return (s->top == 0) ;
}

