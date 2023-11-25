//버블정렬

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y 값을 교환

//int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n) {	//버블정렬 오름차순
	
	int i, j, temp;	//갱신되는 초기 위치, 갱신되는 최소 찾는 위치, 최소의 위치, 저장

	int num = 0;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1]) {	//j+1이 더 작을시
				SWAP(list[j], list[j + 1], temp);

				printf("====cycle %d====\n", ++num);
				for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
					printf("%d ", list[q]);
				printf("\n");
			}
	}
	printf("\n");
}

void bubble_sort2(int list[], int n) {	//버블정렬 내림차순

	int i, j, temp;	//갱신되는 초기 위치, 갱신되는 최소 찾는 위치, 최소의 위치, 저장

	int num = 0;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] < list[j + 1]) {	//j+1이 더 클시
				SWAP(list[j], list[j + 1], temp);

				printf("====cycle %d====\n", ++num);
				for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
					printf("%d ", list[q]);
				printf("\n");
			}
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

	bubble_sort(list, n);  //선택정렬 오름차순 시작
	
	printf("버블정렬 오름차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");


	bubble_sort2(list, n);  //선택정렬 내림차순 시작

	printf("버블정렬 내림차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.가장 작은것 찾고 위치 저장
	2. 해당 위치랑 제일 첫번째 자리와 swap
*/