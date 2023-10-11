#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void Decrease_key_min_heap(int A[],int i,int key){

    int parent, child, temp;

    if(key >=A[i])
        printf("error new key is not smaller thatn current key\n");
    A[i]=key;

    while(i>1){
        parent=i/2;
        if(A[i]<A[parent]){
            temp=A[i];
            A[i]=A[parent];
            A[parent]=temp;
        }
        i=parent;
    }
}
void Increase_min_heap(int A[], int i, int key) {
    int child, temp;
    if (key <= A[i])
        printf("error new key is not smaller than current key\n");

    A[i] = key;
    do {
        child = i * 2;

        if (A[child] < A[child + 1])
            child++;
        if (A[i] > A[child]) {
            temp = A[i];
            A[i] = A[child];
            A[child] = temp;
        }
        i = child;
    }while(child<=10);
}
int main(){
    int A[11]={0,1,4,2,7,5,3,3,7,8,9};
    Decrease_key_min_heap(A, 4, 3);
    Increase_min_heap(A, 3, 10);

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", A[i]);
    }
return 0;
}
