//��������

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

//int list[MAX_SIZE];
int n;

void insert_sort(int list[], int n) {	//�������� ��������

	int i, j, key;	//unsorted ���� ���� ��ġ, sorted ���� ���� ��ġ, sorted
	
	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted ������ ���� �ʱⰪ
		key = list[i];	//key�� ����

		for (j = i - 1; j >= 0 && list[j] > key; j--)	//sorted ������ �ʱⰪ, Ű���� �� ������
			list[j + 1] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + 1] = key;	//�ƴҽ� �� �ڸ��� �״�� ����

		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
	
}

void insert_sort2(int list[], int n) {	//�������� ��������

	int i, j, key;	//unsorted ���� ���� ��ġ, sorted ���� ���� ��ġ, sorted

	int num = 0;

	for (i = 1; i < n; i++) {	//unsorted ������ ���� �ʱⰪ
		key = list[i];	//key�� ����

		for (j = i - 1; j >= 0 && list[j] < key; j--)	//sorted ������ �ʱⰪ, Ű���� �� Ŭ��
			list[j + 1] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + 1] = key;	//�ƴҽ� �� �ڸ��� �״�� ����

		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
}




int main(void) {

	int i;
	n = MAX_SIZE;

	/*srand(time(NULL));
	for (i = 0; i < n; i++)	//������ ����ŭ ���� ����
		list[i] = rand() % 100; //0~99
	*/

	int list[MAX_SIZE] = { 7,4,6,5 };

	insert_sort(list, n);  //�������� �������� ����

	printf("���� ���� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n\n******************************\n\n");

	insert_sort2(list, n);  //�������� �������� ����

	printf("���� ���� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1. sorted �� unsorted ����
	2. sorted �ٷ� ������ ���� key�� ����
	3. key ���� sorted ���� ������ ��������,
*/