#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define  SIZE 5

void print_list(int list[]) {

	for (int i = 0; i < SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
}


#define BUCKETS 10
#define DIGITS  2
void radix_sort(int list[], int n)	//��������
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);  // ť���� �ʱ�ȭ

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)			// �����͵��� �ڸ����� ���� ť�� ����
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		//�ش��ϴ� �� �ڸ����� ����Ʈ�� ����
		//print_list(list);

		for (b = i = 0; b < BUCKETS; b++)  // ��Ŷ���� ������ list�� ��ģ��.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		print_list(list);
		factor *= 10;					// �� ���� �ڸ����� ����.

	}

}

void radix_sort2(int list[], int n)	// ��������
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++)
		init_queue(&queues[b]);  // ť���� �ʱ�ȭ

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++) {
			// �����͵��� �ڸ����� ���� ť�� ����
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}

		for (b = i = 0; b < BUCKETS; b++) {
			while (!is_empty(&queues[b])) {
				// ������������ list �迭 ä���
				list[n - 1 - i] = dequeue(&queues[b]);
				i++;
			}
		}

		// ���ĵ� ��� ���
		print_list(list);
		factor *= 10;
	}
}


int main(void)
{
	int list[SIZE] = { 63, 21, 47, 52, 33 };
	/*
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)      	// ���� ���� �� ���
		list[i] = rand() % 100;
*/

	radix_sort(list, SIZE); // ������� ȣ�� 

	printf("\n===��� ���� ��������===\n");
	print_list(list);

	printf("\n======\n");

	radix_sort2(list, SIZE); // ������� ȣ�� 
	printf("\n===��� ���� ��������===\n");
	print_list(list);

	return 0;
}