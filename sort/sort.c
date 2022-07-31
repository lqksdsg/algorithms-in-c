#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
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
            if(a[i] > a[j])
                swap(a, i , j);
        }
    }

}

//获取中间数的index
static int partition(int *a, int lo, int hi){
    int i = lo;
    int j = hi+1;
    //将p放到中间位置
    int p = a[lo];
    while(1){
        while(a[++i] < p){
            if(i == hi){
                break;
            }
        }
        while(a[--j] >= p){
            if(j == lo){
                break;
            }
        }
        if(i >= j) break;
        swap(a, i, j);
    }
    //此时，a[j] < p，所以将p放到a[lo]
    swap(a, lo, j);
    return j;
}

//快排，[a1...p...an]
//原理：sort([a1...p-1]) + p + sort([p+1...an])
static void _quick_sort(int *a, int i, int j){
    if(i >= j){
        return;
    }
    int pIndex = partition(a, i, j);
    _quick_sort(a, i, pIndex-1);
    _quick_sort(a, pIndex+1, j);
}

void quick_sort(int *a, int len){
    int randIndex = rand() % (len - 1);
    swap(a, randIndex, 0);
    _quick_sort(a, 0, len-1);
}
static int *aux;

//原地归并
static void merge(int *a, int lo, int mid, int hi){
    int i = lo;
    int j = mid+1;
    for(int k = lo;k<=hi;k++){
        aux[k] = a[k]; //先复制一遍
    }
    for(int k = lo;k<=hi;k++){
        if(i > mid){
            a[k] = aux[j++];
        }
        else if(j > hi){
            a[k] = aux[i++];
        }
        else if(aux[j] < aux[i]){
            a[k] = aux[j++];
        }else{
            a[k] = aux[i++];
        }
    }
}

//需要复制元素
//自顶向下
static void _merge_sort(int *a, int lo, int hi){
    if(lo >= hi) return;
    int mid = lo +  (hi - lo)/2;
    _merge_sort(a, lo, mid);
    _merge_sort(a, mid+1, hi);
    merge(a, lo, mid, hi);
}

//归并排序
//a[1..n] = merge(sort(a[1..n/2]), sort(a[n/2..n]))
void merge_sort(int *a, int len){
    aux = (int *)malloc(len);
    _merge_sort(a, 0, len-1);
    free(aux);
}

//堆排序
void heap_sort(int *a, int len){

}