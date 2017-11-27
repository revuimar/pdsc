#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
	stack test;
	init(&test, 1);
	for(int i = 0; i < 1100; i++){
		push(&test, i);
		printf("pushed %d value to %d\n", i, test.top);
	}
	for(int i = 0; i < 1100; i++){
		printf("%d\n", pop(&test));
	}
	destroy(&test);
	return 0;
}