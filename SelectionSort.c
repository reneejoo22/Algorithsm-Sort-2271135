//기수정렬

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
		error("큐가 포화 상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(QueueType* q) {

	if (is_empty(q))
		error("큐가 공백 상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 5
#define DIGITS 4

void radix_sort(int list[], int n) {
	
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);	//큐들 초기화

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++)	//데이터들의 자리수에 따라 큐에 삽입
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
	for (i = 0; i < n; i++)	//정해진 값만큼 난수 생성
		list[i] = rand() % 100; //0~99
	*/

	radix_sort(list, SIZE);  //선택정렬 오름차순 시작
	
	printf("기수 정렬 오름차순 결과\n");
	for (int i = 0; i < SIZE; i++)	//정렬된 것 순서대로 출력
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");

	/*
	selection_sort2(list, n);  //선택정렬 내림차순 시작

	printf("선택 정렬 내림차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");
	*/
	return 0;
}