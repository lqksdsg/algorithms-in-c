#include "sort.h"

static void swap(int *a, int i , int j);

static void swap(int *a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
//插入排序
void insert_sort(int *a, int len){
    if(a == NULL || len <2){
        return;
    }
    int j;
    for(j = 1;j<len;j++){
        //此为核心点：从前到后交换元素，将需插入的元素先保存到一个变量，
        //然后通过轮流赋值来交换元素，无需swap，减少指令数量，提高性能
        int key = a[j];
        int i = j-1;
        while(i >= 0 && a[i] > key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}
//冒泡排序
void bubble_sort(int *a, int len){
    if(a == NULL || len < 2){
        return;
    }
    int i, j;
    for(i = 0;i<len;i++){
        for(j = i+1;j < len;j++){
            swap(a, i , j);
        }
    }

}
//快排，[a1...p...an]
//原理：sort([a1...p-1]) + p + sort([p+1...an])
void quick_sort(int *a, int len){

}

//归并排序
void merge_sort(int *a, int len){

}