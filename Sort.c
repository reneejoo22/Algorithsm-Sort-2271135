//쉘정렬_삽입 정렬의 더 나은 버전

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y 값을 교환

//int list[MAX_SIZE];
int n;

void inc_insertion_sort(int list[], int first, int last, int gap) {	//내림차순

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//반토막 낸 내에서
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)	// 키값이 더 작을시
			list[j + gap] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + gap] = key;	//아닐시 그 자리에 그대로 있음
	}

}

void inc_insertion_sort2(int list[], int first, int last, int gap) {	//오름차순

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//반토막 낸 내에서
		key = list[i];
		for (j = i - gap; j >= first && list[j] < key; j = j - gap)	// 키값이 더 클시
			list[j + gap] = list[j];	//sorted 초기값이 오른쪽으로 옮겨감
		list[j + gap] = key;	//아닐시 그 자리에 그대로 있음
	}

}

void shell_sort(int list[], int n) {

	int i, gap;	

	for (gap = n / 2; gap > 0; gap = gap /2) {	//반토막 낸 값 계속 보내줘야됨
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}

}

void shell_sort2(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//반토막 낸 값 계속 보내줘야됨
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort2(list, i, n - 1, gap);
	}
}



int main(void) {

	int i;
	n = MAX_SIZE;

	/*srand(time(NULL));
	for (i = 0; i < n; i++)	//정해진 값만큼 난수 생성
		list[i] = rand() % 100; //0~99
	*/

	int list[MAX_SIZE] = { 7,4,6,5 };

	shell_sort(list, n);  //쉘정렬 오름차순 시작
	
	printf("쉘정렬 오름차순 결과\n");
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	
	printf("\n\n******************************\n\n");

	printf("쉘정렬 오름차순 결과\n");
	shell_sort2(list, n);  //쉘정렬 오름차순 시작
	for (i = 0; i < n; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.가장 작은것 찾고 위치 저장
	2. 해당 위치랑 제일 첫번째 자리와 swap
*/