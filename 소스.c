//���������ڵ�

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))	//x,y ���� ��ȯ

//int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {	//�������� ��������
	
	int i, j, least, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ּ� ã�� ��ġ, �ּ��� ��ġ, ����

	int num = 0;

	printf("�������� �������� ����\n\n");

	for (i = 0; i < n - 1; i++) {	//�ʱ� �ڸ� �����ϰ� ã��
		least = i;	//i�� �ʱ� �ڸ� ����
		for (j = i + 1; j < n; j++)	//�ʱ� �ڸ� ���ϰ� �ּڰ� Ž��
			if (list[j] < list[least])least = j;	// �ʱ⺸�� ���� �� ã���� �ش� �� ��ġ ����
		SWAP(list[i], list[least], temp);	//�ٲٱ�


		printf("====cycle %d====\n", ++num);
		for (int q = 0; q < n; q++)	//���ĵ� �� ������� ���
			printf("%d ", list[q]);
		printf("\n");
	}
	printf("\n");
}

void selection_sort2(int list[], int n) {	//�������� ��������

	int i, j, least, temp;	//���ŵǴ� �ʱ� ��ġ, ���ŵǴ� �ִ� ã�� ��ġ, �ִ��� ��ġ, ����
	
	int num = 0;

	printf("�������� �������� ����\n\n");
	
	for (i = 0; i < n - 1; i++) {	//�ʱ� �ڸ� �����ϰ� ã��
		least = i;	//i�� �ʱ� �ڸ� ����
		for (j = i + 1; j < n; j++)	//�ʱ� �ڸ� ���ϰ� �ִ� Ž��
			if (list[j] > list[least])least = j;	// �ʱ⺸�� ū �� ã���� �ش� �� ��ġ ����
		SWAP(list[i], list[least], temp);	//�ٲٱ�
		
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

	selection_sort(list, n);  //�������� �������� ����
	
	printf("���� ���� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ",list[i]);
	printf("\n\n******************************\n\n");


	selection_sort2(list, n);  //�������� �������� ����

	printf("���� ���� �������� ���\n");
	for (i = 0; i < n; i++)	//���ĵ� �� ������� ���
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

/*
	1.���� ������ ã�� ��ġ ����
	2. �ش� ��ġ�� ���� ù��° �ڸ��� swap
*/