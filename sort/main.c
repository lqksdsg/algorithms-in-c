#include "sort.h"
#include <stdio.h>
static int test_equal(int *a, int len1, int *b, int len2){
    if(len1 != len2){
        return 0;
    }
    else{
        int i = 0,j = 0;
        for(;i < len1,j < len2;i++, j++){
            if(a[i] != b[j]) return 0;
        }
    }
    return 1;
}

static int test_data[][2][10] = {
    {
        {12,3,4,5,22,44,99,100,-1,2},
        {-1,2,3,4,5,12,22,44,99,100}
    },
    { 
        {1,23,4,2,2,-1,-2,-3,-4,-5},
        {-5,-4,-3,-2,-1,1,2,2,4,23}
    },
    {
        {23,4,2324,25234,21124,-1,-2,0,-3,-4},
        {-4,-3,-2,-1,0,4,23,2324,21124,25234}
    }
};

void test(){
    for(int i = 0;i< sizeof(test_data)/sizeof(test_data[0]);i++){
        quick_sort(test_data[i][0], 10);
        if(test_equal(test_data[i][0], 10, test_data[i][1], 10) == 1){
            for(int j = 0;j<10;j++){
                printf("%d,", test_data[i][0][j]);
            }
            printf("\n");
            printf("pass!\n");
        }
        else{
                for(int j = 0;j<10;j++){
                printf("%d,", test_data[i][0][j]);
            }
            printf("\n");
            printf("not pass!!\n");
        }
    }
}


//test sort algorithm
int main(){
    test();
    return 0;
}