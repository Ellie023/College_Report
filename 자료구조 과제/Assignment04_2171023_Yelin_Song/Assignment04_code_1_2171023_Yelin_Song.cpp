
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct StackNode {
    element item;
    struct StackNode *llink;
    struct StackNode *rlink;
} StackeNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
    s->top = NULL;

}
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    } else {
        temp->item = item;

        if (is_empty(s)) {
            s->top = temp;
            s->top->llink = NULL;
            s->top->rlink = NULL;
        }
        else {
            temp->rlink = s->top;
            temp->rlink->llink=temp;
            s->top = temp;
            s->top->llink=NULL;
        }

    }
}
element pop(LinkedStackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        StackNode *temp = s->top;
        int item = temp->item;
        s->top = s->top->rlink;
        free(temp);
        return item;
    }
}

element peek(LinkedStackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}

int main()
{
    LinkedStackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}








