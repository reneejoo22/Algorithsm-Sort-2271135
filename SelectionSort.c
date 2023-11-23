//선택정렬

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y 값을 교환

//int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {	//선택정렬 오름차순
	
	int i, j, least, temp;	//갱신되는 초기 위치, 갱신되는 최소 찾는 위치, 최소의 위치, 저장

	int num = 0;

	printf("선택정렬 오름차순 시작\n\n");

	for (i = 0; i < n - 1; i++) {	//초기 자리 제외하고 찾기
		least = i;	//i에 초기 자리 저장
		for (j = i + 1; j < n; j++)	//초기 자리 제하고 최솟값 탐색
			if (list[j] < list[least])least = j;	// 초기보다 작은 값 찾으면 해당 값 위치 저장
		SWAP(list[i], list[least], temp);	//바꾸기


		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
}

void selection_sort2(int list[], int n) {	//선택정렬 내림차순

	int i, j, least, temp;	//갱신되는 초기 위치, 갱신되는 최대 찾는 위치, 최대의 위치, 저장
	
	int num = 0;

	printf("선택정렬 내림차순 시작\n\n");
	
	for (i = 0; i < n - 1; i++) {	//초기 자리 제외하고 찾기
		least = i;	//i에 초기 자리 저장
		for (j = i + 1; j < n; j++)	//초기 자리 제하고 최댓값 탐색
			if (list[j] > list[least])least = j;	// 초기보다 큰 값 찾으면 해당 값 위치 저장
		SWAP(list[i], list[least], temp);	//바꾸기
		
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

	selection_sort(list, n);  //선택정렬 오름차순 시작
	
	printf("선택 정렬 오름차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");


	selection_sort2(list, n);  //선택정렬 내림차순 시작

	printf("선택 정렬 내림차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.가장 작은것 찾고 위치 저장
	2. 해당 위치랑 제일 첫번째 자리와 swap
*/