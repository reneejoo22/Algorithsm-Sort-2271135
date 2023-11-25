//��������

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y ���� ��ȯ

//int list[MAX_SIZE];
int n;

void bubble_sort(int list[], int n) {	//�������� ��������
	
	int i, j, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ּ� ã�� ��ġ, �ּ��� ��ġ, ����

	int num = 0;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1]) {	//j+1�� �� ������
				SWAP(list[j], list[j + 1], temp);

				printf("====cycle %d====\n", ++num);
				for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
					printf("%d ", list[q]);
				printf("\n");
			}
	}
	printf("\n");
}

void bubble_sort2(int list[], int n) {	//�������� ��������

	int i, j, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ּ� ã�� ��ġ, �ּ��� ��ġ, ����

	int num = 0;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] < list[j + 1]) {	//j+1�� �� Ŭ��
				SWAP(list[j], list[j + 1], temp);

				printf("====cycle %d====\n", ++num);
				for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
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
	for (i = 0; i < n; i++)	//������ ����ŭ ���� ����
		list[i] = rand() % 100; //0~99
	*/

	int list[MAX_SIZE] = { 7,4,6,5 };

	bubble_sort(list, n);  //�������� �������� ����
	
	printf("�������� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");


	bubble_sort2(list, n);  //�������� �������� ����

	printf("�������� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.���� ������ ã�� ��ġ ����
	2. �ش� ��ġ�� ���� ù��° �ڸ��� swap
*/