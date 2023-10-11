#include <stdio.h>
#include <stdlib.h>
#include <string>
// heap functions
#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 8
#define INF 1000L
int weight[MAX_VERTICES][MAX_VERTICES] =
        { { 0,3,INF,INF,INF,INF,INF,14 },
          { 3,0,8,INF,INF,INF,INF,10 },
          { INF,8,0,15,2,INF,INF,INF },
          { INF,INF,15,0,INF,INF,INF,INF },
          { INF,INF,2,INF,0,9,4,5 },
          { INF,INF,INF,INF,9,0,INF,INF },
          { INF,INF,INF,INF,4,INF,0,6 },
          { 14,10,INF,INF,5,INF,6,0 } };

int selected[MAX_VERTICES];
// Definition of element type in heap
typedef struct element{
    int key; // edge weight
    int u; // vertex 1
    int v; // vertex 2
} element;
typedef struct HeapType{
    element heap[MAX_VERTICES];
    int heap_size;
} HeapType;
void init(HeapType *h){
    h->heap_size=0;
}


void insert_min_heap(HeapType *h, element item) {
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}
void build_min_heap(HeapType *h){
    int j=h->heap_size;
    element tmp;
    j/=2;
    while (j>0){
        tmp=h->heap[j];
        if((2*j<=h->heap_size)&&(h->heap[j].v>h->heap[2*j].v)){
            h->heap[j]=h->heap[j*2];
            h->heap[j*2]=tmp;
        }
        tmp=h->heap[j];
        if((2*j+1<=h->heap_size)&&(h->heap[j].v>h->heap[2*j+1].v)){
            h->heap[j]=h->heap[j*2+1];
            h->heap[j*2+1]=tmp;
        }
        j--;

    }

}
element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].v) > h->heap[child + 1].v)
            child++;
        if (temp.v <= h->heap[child].v) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].u) > h->heap[child + 1].u)
            child++;
        if (temp.u <= h->heap[child].u) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void Decrease_key_min_heap(HeapType *A,int i,int key){

    int parent, child, temp;

    if(key >=A->heap[i].key)
        printf("error new key is not smaller than current key\n");
    A->heap[i].key=key;

    while(i>1){
        parent=i/2;
        if(A->heap[i].v<A->heap[parent].v){
            temp=A->heap[i].v;
            A->heap[i].v=A->heap[parent].v;
            A->heap[parent].v=temp;
        }
        i=parent;
    }
}
int get_min_vertex(HeapType *A,int n)
{
    int v, i;
    for (i = 0; i <n; i++)
        if (!selected[i]) {
            v = i;
            break;
        }
    for (i = 0; i < n; i++)
        if (!selected[i] && (A->heap[i].key< A->heap[v].key)) v = i;
    return (v);
}

void prim(HeapType *A,int s, int n)
{
    int i, u, v;
    for (u = 0; u<n; u++)
    {
        A->heap[u].key = INF;
        selected[u] = FALSE;
        A->heap_size++;
    }
    A->heap[s].key = 0;
    for (i = 0; i<n; i++) {
        u = get_min_vertex(A,n);
        selected[u] = TRUE;
        if (A->heap[u].key == INF) return;
        for (v = 0; v<n; v++)
            if (weight[u][v] != INF)
                if (!selected[v] && weight[u][v]< A->heap[v].key) {
                    A->heap[v].u=u;
                    A->heap[v].v=v;
                    A->heap[v].key=weight[u][v];

                }
    }
    int edge_accepted = 0; // The number of edges selected
    int uset, vset; // Set number of vertex u and v
    element e;
    build_min_heap(A);
    while (edge_accepted <= (n - 1)) // The number of edges selected < (n-1)
    {
        e = delete_min_heap(A); // Delete from the min heap
        uset = e.u;
        vset = e.v;
        if (uset != vset) { // if they belong to different sets
            printf("vertex %d -> %d edge: %d \n", e.u, e.v, e.key);
            edge_accepted++;
        }
    }
}

int main()
{
    HeapType *A = (HeapType *)malloc(sizeof(HeapType));
    init(A);
    prim(A,0, MAX_VERTICES);

    return 0;
}
