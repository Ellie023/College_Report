#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void counting_sort(unsigned int A[],unsigned int B[],int k,int d){
    unsigned int i,j;
    unsigned int *C=(unsigned int*) malloc(sizeof(unsigned int)*k);
    for(i=0; i<k; i++)
        C[i]=0;
    for (j = 0; j < SIZE; j++)
        C[(A[j]>>(d*6))&(63)] += 1;
    for(i=1; i<k; k++)
        C[i]=C[i]+C[i-1];
    for(unsigned j=SIZE-1; j>0; j--){
        B[(A[j]>>(d*6))&(63)]=A[j];
        C[(A[j]>>(d*6))&(63)]-=1;
    }
}
void radix_sort(unsigned int list[], int n){
    int i,d;
    unsigned int *B=(unsigned int*) malloc(sizeof(unsigned int)*SIZE);
    unsigned int A[SIZE]={0},c[SIZE]={0};
    for(d=0; d<n; d++){
        counting_sort(list,B,64,d);
        for(i=0; i<SIZE; i++){
            list[i]=B[i];
        }
    }


}

int main() {
    unsigned int *list=(unsigned int*) malloc(sizeof(unsigned int)*SIZE);
    int i;
    srand(time(NULL));
    for(i=0; i<SIZE; i++){
        list[i]=rand()%4096;
        list[i]*=rand()%4096;
        list[i]-=1;
    }
    radix_sort(list,4);

    for(i=0; i<SIZE; i++)
        printf("%u\n",list[i]);

    return 0;
}
