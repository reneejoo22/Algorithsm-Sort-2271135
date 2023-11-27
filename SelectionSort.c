#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;

		
	}
	
	h->heap[i] = item;     // 새로운 노드를 삽입
	
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}


// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n, int choice)
{
	int i;
	HeapType* h;

	h = create();
	init(h);

	if (choice == 0) {
		for (i = 0; i < n; i++) {
			insert_max_heap(h, a[i]);
		}

		for (i = (n - 1); i >= 0; i--) {
			a[i] = delete_max_heap(h);
		}
	}

	else {
		for (i = 0; i < n; i++) {
			insert_min_heap(h, a[i]);
		}
		for (i = (n - 1); i >= 0; i--) {
			a[i] = delete_min_heap(h);
		}
	}

	
	free(h);
}

#define SIZE 4
int main(void)
{
	element list[SIZE] = { 7, 4, 6, 5 };

	printf("히프 정렬 오름차순\n");
	heap_sort(list, SIZE, 0);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");

	printf("히프 정렬 내림차순\n");
	heap_sort(list, SIZE, 1);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");

	return 0;
}