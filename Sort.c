//������_���� ������ �� ���� ����

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y ���� ��ȯ

//int list[MAX_SIZE];
int n;

void inc_insertion_sort(int list[], int first, int last, int gap) {	//��������

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//���丷 �� ������
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)	// Ű���� �� ������
			list[j + gap] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + gap] = key;	//�ƴҽ� �� �ڸ��� �״�� ����
	}

}

void inc_insertion_sort2(int list[], int first, int last, int gap) {	//��������

	int i, j, key;

	for (i = first + gap; i <= last; i = i + gap) {	//���丷 �� ������
		key = list[i];
		for (j = i - gap; j >= first && list[j] < key; j = j - gap)	// Ű���� �� Ŭ��
			list[j + gap] = list[j];	//sorted �ʱⰪ�� ���������� �Űܰ�
		list[j + gap] = key;	//�ƴҽ� �� �ڸ��� �״�� ����
	}

}

void shell_sort(int list[], int n) {

	int i, gap;	

	for (gap = n / 2; gap > 0; gap = gap /2) {	//���丷 �� �� ��� ������ߵ�
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}

}

void shell_sort2(int list[], int n) {

	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2) {	//���丷 �� �� ��� ������ߵ�
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort2(list, i, n - 1, gap);
	}
}



int main(void) {

	int i;
	n = MAX_SIZE;

	/*srand(time(NULL));
	for (i = 0; i < n; i++)	//������ ����ŭ ���� ����
		list[i] = rand() % 100; //0~99
	*/

	int list[MAX_SIZE] = { 7,4,6,5 };

	shell_sort(list, n);  //������ �������� ����
	
	printf("������ �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	
	printf("\n\n******************************\n\n");

	printf("������ �������� ���\n");
	shell_sort2(list, n);  //������ �������� ����
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.���� ������ ã�� ��ġ ����
	2. �ش� ��ġ�� ���� ù��° �ڸ��� swap
*/