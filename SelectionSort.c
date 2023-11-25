//퀵 정렬, t(퀵정렬, 라이브러리 함수 사용)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 4
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp)) // x, y 값을 교환

int list[MAX_SIZE];
int n;

int compare(const void* x, const void* y) {
    return (*(int*)x - *(int*)y); // 오름차순
}
int compare2(const void* x, const void* y) {
    return (*(int*)y - *(int*)x); // 내림차순
}

void print_list(int list[], int n) {

    for (int i = 0; i < n; i++) // 정렬된 것 순서대로 출력
        printf("%d ", list[i]);
    printf("\n");
}

int partition(int list[], int left, int right) {    //오름
    
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do
            low++;
        while (list[low] < pivot);  //low가 더 작은 경우 탐색 계속 진행
        
        do
            high--;
        while (list[high] > pivot); //high가 더 큰 경우 탐색 계속 진행

        if (low < high) {
            SWAP(list[low], list[high], temp);   //와일문에 반할시 둘의 값 바꿈


            print_list(list, MAX_SIZE);
        }
    
    } while (low < high);   //둘이 교차하면 탐색 멈춤

    SWAP(list[left], list[high], temp);
    
    print_list(list, MAX_SIZE);

    return high;
}

int partition2(int list[], int left, int right) {   //내림

    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do {
        do
            low++;
        while (list[low] > pivot);  //low가 더 작은 경우 탐색 계속 진행

        do
            high--;
        while (list[high] < pivot); //high가 더 큰 경우 탐색 계속 진행

        if (low < high) {
            SWAP(list[low], list[high], temp);   //와일문에 반할시 둘의 값 바꿈
           
            print_list(list, MAX_SIZE);
        }
    } while (low < high);   //둘이 교차하면 탐색 멈춤

    SWAP(list[left], list[high], temp);
    print_list(list, MAX_SIZE);

    return high;
}


void quick_sort(int list[], int left, int right, int choice) {

    if (left < right) {
        if (choice == 0) {
            int q = partition(list, left, right, choice);
            quick_sort(list, left, q - 1, choice);  //왼쪽만 정렬진행
            quick_sort(list, q + 1, right, choice); //른쪽만 정렬진행
        }
        else {
            int q = partition2(list, left, right, choice);
            quick_sort(list, left, q - 1, choice);  //왼쪽만 정렬진행
            quick_sort(list, q + 1, right, choice); //른쪽만 정렬진행

        }
    }
}



int main(void) {

    int i;
    n = MAX_SIZE;
    /*
    srand(time(NULL));
    for (i = 0; i < n; i++) // 정해진 값만큼 난수 생성
        list[i] = rand() % 100; // 0~99
        */

    int list[MAX_SIZE] = { 6, 7, 4, 5 };

    quick_sort(list, 0, n - 1, 0); // 선택정렬 오름차순(0) 시작

    printf("퀵 정렬 오름차순 결과\n");
    print_list(list, n);
    printf("\n\n******************************\n\n");

    quick_sort(list, 0, n - 1, 1); // 선택정렬 내림차순(1) 시작
    printf("퀵 정렬 내림차순 결과\n");
    print_list(list ,n);

    printf("\n[오름]퀵 라이버리 함수 사용 결과\n");
    qsort(list, MAX_SIZE, sizeof(int),compare);
    print_list(list, n);

    printf("\n[내림]퀵 라이버리 함수 사용 결과\n");
    qsort(list, MAX_SIZE, sizeof(int), compare2);
    print_list(list, n);


    return 0;
}