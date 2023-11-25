//삽입정렬

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

//int list[MAX_SIZE];
int n;

void insert_sort(int list[], int n) {	//삽입정렬 오름차순

	int i, j, key;	//unsorted 영역 내의 위치, sorted 영역 내의 위치, sorted
	
	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted 영역의 가장 초기값
		key = list[i];	//key에 저장

		for (j = i - 1; j >= 0 && list[j] > key; j--)	//sorted 영역의 초기값, 키값이 더 작을시
			list[j + 1] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + 1] = key;	//아닐시 그 자리에 그대로 있음

		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
	
}

void insert_sort2(int list[], int n) {	//삽입정렬 내림차순

	int i, j, key;	//unsorted 영역 내의 위치, sorted 영역 내의 위치, sorted

	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted 영역의 가장 초기값
		key = list[i];	//key에 저장

		for (j = i - 1; j >= 0 && list[j] < key; j--)	//sorted 영역의 초기값, 키값이 더 클시
			list[j + 1] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + 1] = key;	//아닐시 그 자리에 그대로 있음

		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
}




int main(void) {

	int i;
	n = MAX_SIZE;

	/*srand(time(NULL));
	for (i = 0; i < n; i++)	//정해진 값만큼 난수 생성
		list[i] = rand() % 100; //0~99
	*/

	int list[MAX_SIZE] = { 7,4,6,5 };

	insert_sort(list, n);  //선택정렬 오름차순 시작

	printf("삽입 정렬 오름차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n\n******************************\n\n");

	insert_sort2(list, n);  //선택정렬 내림차순 시작

	printf("삽입 정렬 내림차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1. sorted 와 unsorted 나눔
	2. sorted 바로 다음의 값을 key에 저장
	3. key 보다 sorted 값이 작으면 왼쪽으로,
*/