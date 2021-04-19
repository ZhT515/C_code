#include"Stack.h"

void TEST()
{
	Stack ps;

	StackInit(&ps);
	
	if (!StackEmpty(&ps))
		printf("00000\n");

	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);

	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
}

int main()
{
	TEST();
}