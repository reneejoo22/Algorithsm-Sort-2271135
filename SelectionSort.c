//�������

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {

	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	
	return (q->front == q->rear);
}

int is_full(QueueType* q) {

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {

	if (is_full(q))
		error("ť�� ��ȭ ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q) {

	if (is_empty(q))
		error("ť�� ���� ����");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 4

void radix_sort(int list[], int n) {
	
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
	}

	for (b = i = 0; b < BUCKETS; b++) {
		while (!is_empty(&queues[b]))
			list[i++] = dequeue(&queues[b]);
		factor *= 10;
	}
}

#define SIZE 5

int main(void) {
	
	int list[SIZE] = {63, 21, 47, 52, 33};

	//n = MAX_SIZE;

	/*srand(time(NULL));
	for (i = 0; i < n; i++)	//������ ����ŭ ���� ����
		list[i] = rand() % 100; //0~99
	*/



	radix_sort(list, SIZE);  //�������� �������� ����
	
	printf("���� ���� �������� ���\n");
	for (int i = 0; i < SIZE; i++)	//���ĵ� �� ������� ���
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");

	/*
	selection_sort2(list, n);  //�������� �������� ����

	printf("���� ���� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");
	*/
	return 0;
}

/*
	1.���� ������ ã�� ��ġ ����
	2. �ش� ��ġ�� ���� ù��° �ڸ��� swap
*/