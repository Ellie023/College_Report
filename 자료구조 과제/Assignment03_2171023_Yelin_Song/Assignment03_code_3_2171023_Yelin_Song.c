#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    int lenght;
}ListType;
ListType list1;
void init(ListType *plist){
    plist->lenght=0;
    plist->head=plist->tail==NULL;
}
void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}
int is_empty(ListType *list){
    if(list->head==NULL) return 1;
    else return 0;
}

void insert_node(ListType *list, ListNode *p, ListNode *node){
    if(list->head==NULL){
        node->link=NULL;
        list->head=list->tail=node;
    }
    else{
        if(p==NULL){
            printf("The Preceding node cannot be NULL \n");
            exit(1);
        }
        else{
            node->link=p->link;
            p->link=node;
        }
    }
}

void add_first(ListType *list,int data) {
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->data=data;
    if(list->head==NULL){
        p->link=NULL;
        list->head=list->tail=p;
    }
    else{
        p->link=list->head;
        list->head=p;
    }
    list->lenght++;
    }

void add_last(ListType *list,int data){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    p->data=data;
    ListNode *last=list->head;
    while(last->link!=NULL){
        last=last->link;
    }
    list->tail=last;
    list->tail->link=NULL;
    if(list->tail==NULL){
        p->link=NULL;
        list->head=list->tail=p;
    }
    else{
        list->tail->link=p;
        p->link=NULL;
        list->tail=p;
    }
    list->lenght++;
}
ListNode *get_node_at(ListType *list, int pos){
        int i;
        ListNode *tmp_node=list->head;
        if(pos<0) return NULL;
        for(i=0; i<pos; i++){
            tmp_node=tmp_node->link;}
        return tmp_node;
}

void add(ListType *list, int position,element data){
    ListNode *p;
    if((position>=0)&&(position<=list->lenght)){
        ListNode *node=(ListNode*) malloc(sizeof(ListNode));
        if(node==NULL) error("Memory allocation error");
        node->data=data;
        p= get_node_at(list,position-1);
        insert_node(&(list->head),p,node);
        list->lenght++;
    }
}
void remove_node(ListType *list, ListNode *p, ListNode *removed){
     if(list==NULL)
         printf("error");
     else{
         p->link=removed->link;
         free(removed);
     }
}
void delete(ListType *list, int pos){
    if(!is_empty(list)&&(pos>=0)&&(pos<list->lenght)){
        ListNode *p = get_node_at(list, pos - 1);
        ListNode *removed = get_node_at(list, pos);
        remove_node(&(list->head),p,removed);
        list->lenght--;}
}
void delete_first(ListType *list){
    ListNode *removed;
    if(list->head==NULL) printf("error");
    else {
        removed = list->head;
        list->head = removed->link;
        free(removed);
        list->lenght--;
    }
}
void delete_last(ListType *list){
    ListNode *last_before=list->head;
    while(last_before->link->link!=NULL){
        last_before=last_before->link;
    }
    list->tail=last_before->link;
    if(list->tail==NULL) printf("error");
    else{
        free(list->tail);
        list->tail=last_before;
        list->tail->link=NULL;
    }
    list->lenght--;
}

void display(ListType *list){
    int i;
    ListNode *node=list->head;
    printf("( ");
    for(i=0; i<list->lenght; i++){
        printf("%d ",node->data);
        node=node->link;
    }
    printf(" )\n");
}
#define FALSE 0
#define TRUE !FALSE
int is_in_list(ListType *list, int item){
    ListNode *p;
    p=list->head;
    while(p!=NULL){
        if(p->data==item)
            break;
        p=p->link;
    }
    if(p==NULL) return FALSE;
    else return TRUE;
}
element get_entry(ListType *list,int pos){
    ListNode *p;
    if(pos>=list->lenght)error("Positio error");
    else{
        p= get_node_at(list,pos);
        return p->data;
    }
}
int main() {
    ListType list1;
    init(&list1);
    add_first(&list1,20);
    add_last(&list1,30);
    add_first(&list1,10);
    add_last(&list1,40);
    add(&list1,2,70);
    display(&list1);

    delete(&list1,2);
    delete_first(&list1);
    delete_last(&list1);
    display(&list1);

    printf("%s\n", is_in_list(&list1,20)==TRUE?"TRUE":"FALSE");
    printf("%d\n",get_entry(&list1,0));

    return 0;
}
