//�� ����, t(������, ���̺귯�� �Լ� ���)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 4
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp)) // x, y ���� ��ȯ

int list[MAX_SIZE];
int n;

int compare(const void* x, const void* y) {
    return (*(int*)x - *(int*)y); // ��������
}
int compare2(const void* x, const void* y) {
    return (*(int*)y - *(int*)x); // ��������
}

void print_list(int list[], int n) {

    for (int i = 0; i < n; i++) // ���ĵ� �� ������� ���
        printf("%d ", list[i]);
    printf("\n");
}

int partition(int list[], int left, int right) {    //����
    
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do
            low++;
        while (list[low] < pivot);  //low�� �� ���� ��� Ž�� ��� ����
        
        do
            high--;
        while (list[high] > pivot); //high�� �� ū ��� Ž�� ��� ����

        if (low < high) {
            SWAP(list[low], list[high], temp);   //���Ϲ��� ���ҽ� ���� �� �ٲ�


            print_list(list, MAX_SIZE);
        }
    
    } while (low < high);   //���� �����ϸ� Ž�� ����

    SWAP(list[left], list[high], temp);
    
    print_list(list, MAX_SIZE);

    return high;
}

int partition2(int list[], int left, int right) {   //����

    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do
            low++;
        while (list[low] > pivot);  //low�� �� ���� ��� Ž�� ��� ����

        do
            high--;
        while (list[high] < pivot); //high�� �� ū ��� Ž�� ��� ����

        if (low < high) {
            SWAP(list[low], list[high], temp);   //���Ϲ��� ���ҽ� ���� �� �ٲ�
           
            print_list(list, MAX_SIZE);
        }
    } while (low < high);   //���� �����ϸ� Ž�� ����

    SWAP(list[left], list[high], temp);
    print_list(list, MAX_SIZE);

    return high;
}


void quick_sort(int list[], int left, int right, int choice) {

    if (left < right) {
        if (choice == 0) {
            int q = partition(list, left, right, choice);
            quick_sort(list, left, q - 1, choice);  //���ʸ� ��������
            quick_sort(list, q + 1, right, choice); //���ʸ� ��������
        }
        else {
            int q = partition2(list, left, right, choice);
            quick_sort(list, left, q - 1, choice);  //���ʸ� ��������
            quick_sort(list, q + 1, right, choice); //���ʸ� ��������

        }
    }
}



int main(void) {

    int i;
    n = MAX_SIZE;
    /*
    srand(time(NULL));
    for (i = 0; i < n; i++) // ������ ����ŭ ���� ����
        list[i] = rand() % 100; // 0~99
        */

    int list[MAX_SIZE] = { 6, 7, 4, 5 };

    quick_sort(list, 0, n - 1, 0); // �������� ��������(0) ����

    printf("�� ���� �������� ���\n");
    print_list(list, n);
    printf("\n\n******************************\n\n");

    quick_sort(list, 0, n - 1, 1); // �������� ��������(1) ����
    printf("�� ���� �������� ���\n");
    print_list(list ,n);

    printf("\n[����]�� ���̹��� �Լ� ��� ���\n");
    qsort(list, MAX_SIZE, sizeof(int),compare);
    print_list(list, n);

    printf("\n[����]�� ���̹��� �Լ� ��� ���\n");
    qsort(list, MAX_SIZE, sizeof(int), compare2);
    print_list(list, n);


    return 0;
}