#include "stack.h"

int main(int argc, char const *argv[])
{
	stack test;
	printf("###############define initialisation size############\n");
	init(&test, 1);
	for(int i = 0; i < 1100; i++){
		push(&test, i);
		printf("pushed %d value to %d\n", i, test.top);
	}
	for(int i = 0; i < 1100; i++){
		printf("%d\n", pop(&test));
	}
	destroy(&test);
	stack test1;
	init(&test1, 1);
	printf("poping empty stack\n");
	printf("%d\n", pop(&test1));
	destroy(&test1);
	return 0;
}