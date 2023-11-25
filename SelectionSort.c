//�պ�����

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
//#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y ���� ��ȯ

int sorted[MAX_SIZE];	//����Ʈ

void merge(int list[], int left, int mid, int right) {	//�պ����� ��������
	
	int i, j, k, l;
	i = left; j = mid + 1; k = left;	//left --- mid     mid+1 --- right

	//int num = 0;

	while (i <= mid && j <= right) {	//mid�� left���� ũ�ų� �� && mid+1�� right���� ������
		if (list[i] <= list[j]) { 	//left �� ������ ������ ù��°��(mid+1)���� ������
			sorted[k++] = list[i++];	//�������� �� ���� left ���� ����Ʈ�� ��
		}	
		else 
			sorted[k++] = list[j++];	//�ƴҽ� �� ���� ���� ������ ù��°��(mid+1)�� ����Ʈ�� �鰨
		}

	if (!((i == j) || (i == 0 && j == 0))) {
		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < MAX_SIZE; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}

	if (i > mid)	//���� �κ� �� ���ĵ� �����ε� ������ �κ� ����������_�����ִ� �� ����  
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];	//�п��� ������ �� �Ϸķ� ����

	else	//������ �κ� �� ���ĵ� �����ε� ���� �κ� ����������_�����ִ� �� ����  
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];	//�п��� ���� �� �Ϸķ� ����
	
	for (l = left; l <= right; l++)	//�迭 �Ϸ�� ���� list�� �Ϸķ� ����
		list[l] = sorted[l];
}

void merge2(int list[], int left, int mid, int right) {	//�պ����� ��������

	int i, j, k, l;
	i = left; j = mid + 1; k = left;	//left --- mid     mid+1 --- right

	while (i <= mid && j <= right) {	//mid�� left���� ũ�ų� �� && mid+1�� right���� ������
		if (list[i] >= list[j])	//left �� ������ ������ ù��°��(mid+1)���� Ŭ��
			sorted[k++] = list[i++];	//�������� �� ū left ���� ����Ʈ�� ��
		else
			sorted[k++] = list[j++];	//�ƴҽ� �� ū ���� ������ ù��°��(mid+1)�� ����Ʈ�� �鰨
	}

	if (!((i == j) || (i == 0 && j == 0))) {
		//printf("====cycle %d====\n", ++num);
		for (int q = 0; q < MAX_SIZE; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}

	if (i > mid)	//���� �κ� �� ���ĵ� �����ε� ������ �κ� ����������_�����ִ� �� ����  
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];	//�п��� ������ �� �Ϸķ� ����
	else	//������ �κ� �� ���ĵ� �����ε� ���� �κ� ����������_�����ִ� �� ����  
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];	//�п��� ���� �� �Ϸķ� ����

	for (l = left; l <= right; l++)	//�迭 �Ϸ�� ���� list�� �Ϸķ� ����
		list[l] = sorted[l];
}


void merge_sort(int list[], int left, int right, int choice) {

	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		//printf("left_%d, mid_%d\n", left, mid);
		merge_sort(list, left, mid, choice);	//���� �κ� ������

		merge_sort(list, mid + 1, right, choice); //������ �κ� ������


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


	merge_sort(list, 0, MAX_SIZE - 1, 0);  //�������� ��������(0) ����
	
	printf("���� ���� �������� ���\n");
	for (int i = 0; i < MAX_SIZE; i++)	//���ĵ� �� ������� ���
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");

	
	merge_sort(list, 0, MAX_SIZE - 1, 1);  //�������� ��������(1) ����

	printf("���� ���� �������� ���\n");
	for (int i = 0; i < MAX_SIZE; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}
