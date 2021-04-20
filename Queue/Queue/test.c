#include"Queue.h"

void TEST()
{
	Queue q;

	QueueInit(&q);
	if (QueueEmpty(&q))
		printf("aaaaaaa\n");
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3); 
	QueuePush(&q, 4);

	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d", QueueSize(&q));
	QueueDestroy(&q);
}

int main()
{
	TEST();
}