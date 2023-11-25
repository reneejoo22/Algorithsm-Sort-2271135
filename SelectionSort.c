//합병정렬

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y 값을 교환

int sorted[MAX_SIZE];	//리스트

void merge(int list[], int left, int mid, int right) {	//합병정렬 오름차순
	
	int i, j, k, l;
	i = left; j = mid + 1; k = left;	//left --- mid     mid+1 --- right

	//int num = 0;

	while (i <= mid && j <= right) {	//mid가 left보다 크거나 같 && mid+1가 right보다 작을때
		if (list[i] <= list[j]) { 	//left 가 나눠진 왼쪽의 첫번째값(mid+1)보다 작을때
			sorted[k++] = list[i++];	//비교했을때 더 작은 left 값이 리스트로 들어감
		}	
		else 
			sorted[k++] = list[j++];	//아닐시 더 작은 값인 왼쪽의 첫번째값(mid+1)이 리스트에 들감
		}

	if (!((i == j) || (i == 0 && j == 0))) {
		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < MAX_SIZE; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}

	if (i > mid)	//왼쪽 부분 다 정렬된 상태인데 오른쪽 부분 남아있을때_남아있는 값 보냄  
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];	//분열된 오른쪽 값 일렬로 보냄

	else	//오른쪽 부분 다 정렬된 상태인데 왼쪽 부분 남아있을때_남아있는 값 보냄  
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];	//분열된 왼쪽 값 일렬로 보냄
	
	for (l = left; l <= right; l++)	//배열 완료된 값을 list에 일렬로 넣음
		list[l] = sorted[l];
}

void merge2(int list[], int left, int mid, int right) {	//합병정렬 내림차순

	int i, j, k, l;
	i = left; j = mid + 1; k = left;	//left --- mid     mid+1 --- right

	while (i <= mid && j <= right) {	//mid가 left보다 크거나 같 && mid+1가 right보다 작을때
		if (list[i] >= list[j])	//left 가 나눠진 왼쪽의 첫번째값(mid+1)보다 클때
			sorted[k++] = list[i++];	//비교했을때 더 큰 left 값이 리스트로 들어감
		else
			sorted[k++] = list[j++];	//아닐시 더 큰 값인 왼쪽의 첫번째값(mid+1)이 리스트에 들감
	}

	if (!((i == j) || (i == 0 && j == 0))) {
		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < MAX_SIZE; q++)	//정렬된 것 순서대로 출력
			printf("%d ", list[q]);
		printf("\n");
	}

	if (i > mid)	//왼쪽 부분 다 정렬된 상태인데 오른쪽 부분 남아있을때_남아있는 값 보냄  
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];	//분열된 오른쪽 값 일렬로 보냄
	else	//오른쪽 부분 다 정렬된 상태인데 왼쪽 부분 남아있을때_남아있는 값 보냄  
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];	//분열된 왼쪽 값 일렬로 보냄

	for (l = left; l <= right; l++)	//배열 완료된 값을 list에 일렬로 넣음
		list[l] = sorted[l];
}


void merge_sort(int list[], int left, int right, int choice) {

	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		//printf("left_%d, mid_%d\n", left, mid);
		merge_sort(list, left, mid, choice);	//왼쪽 부분 나누기

		merge_sort(list, mid + 1, right, choice); //오른쪽 부분 나누기


		if (choice == 0) {
			//printf("merge(left_%d, mid_%d)\n\n", left, mid);
			merge(list, left, mid, right);

		}
		else {
			merge2(list, left, mid, right);
		}
	}
}

int main(void) {
	

	//int list[MAX_SIZE] = { 7,4,6,5 };
	int list[MAX_SIZE] = { 4,6,5,3,2,1,8,7 };


	merge_sort(list, 0, MAX_SIZE - 1, 0);  //선택정렬 오름차순(0) 시작
	
	printf("선택 정렬 오름차순 결과\n");
	for (int i = 0; i < MAX_SIZE; i++)	//정렬된 것 순서대로 출력
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");

	
	merge_sort(list, 0, MAX_SIZE - 1, 1);  //선택정렬 내림차순(1) 시작

	printf("선택 정렬 내림차순 결과\n");
	for (int i = 0; i < MAX_SIZE; i++)	//정렬된 것 순서대로 출력
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}
