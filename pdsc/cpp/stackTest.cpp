#include <stdio.h>
#include "stack.h"

int main()
{
	Stack test;
	for(int i=0; i<5000; i++)
	{
		test.push(i);
		printf("pushed %d value\n", i);
	}
	for(int i=0; i<5000; i++)
	{
		printf("%d\n",test.pop());
	}
	test.clear();
	return 0;
}