#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode *insert_node(ListNode *head, int *data){
    ListNode *p=(ListNode *) malloc(sizeof(ListNode));
    if(head==NULL){
        p->data=data;
       p->link=NULL;
       head=p;
    }
    else {
        p->data = data;
        p->link = head;
        head = p;
    }
    return head;
}
ListNode *insert_last(ListNode *head, int *data){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    if(head==NULL){
        p->data=data;
        p->link=NULL;
        head= p;
    }
    else{
        p->data=data;
        ListNode *last=head;
        while(last->link!=NULL)
            last=last->link;
        last->link=p;
    }
    return head;
}
ListNode *Merge(ListNode *a,ListNode *b){
    ListNode *ap,*bp,*c;
    c=NULL;
    ap=a;
    bp=b;
    if(a==NULL) return b;
    if(b==NULL) return a;
    while (ap != NULL && bp != NULL) {

            if (ap->data < bp->data) {
                c = insert_last(c, ap->data);
                ap = ap->link;
                c->link->data;
            } else if (ap->data > bp->data) {
                c = insert_last(c, bp->data);
                bp = bp->link;

            } else {
                c = insert_last(c, ap->data);
                c = insert_last(c, ap->data);
                ap = ap->link;
                bp = bp->link;
            }
        }
            while (bp != NULL) {
                c= insert_last(c,bp->data);
                bp = bp->link;
            }
            while (ap != NULL) {
                c= insert_last(c,ap->data);
                ap = ap->link;
            }
    return c;
}

void printList(ListNode *head){
    while (head!=NULL) {
        printf("%d, ", head->data);
        head=head->link;
    }
    printf("} \n");
}

int main() {

    ListNode *a=NULL;
    a=insert_node(a, 25);
    a=insert_node(a, 20);
    a=insert_node(a, 15);
    a=insert_node(a, 10);
    a=insert_node(a, 5);
    a=insert_node(a, 2);
    a=insert_node(a, 1);

    ListNode *b = NULL;
    b=insert_node(b, 30);
    b=insert_node(b, 18);
    b=insert_node(b, 15);
    b=insert_node(b, 8);
    b=insert_node(b, 7);
    b=insert_node(b, 3);


    printf("a = {");
    printList(a);
    printf("b = {");
    printList(b);
    ListNode *c= Merge(a,b);
    printf("c = {");

    printList(c);



    return 0;
}