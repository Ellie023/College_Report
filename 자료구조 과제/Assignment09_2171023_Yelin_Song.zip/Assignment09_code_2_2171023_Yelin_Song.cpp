#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int key;
   TreeNode *l;
   TreeNode *r;
}TreeNode;

 int random(int max){
    return rand()%max+1;
}
TreeNode * new_node(int item)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->l = temp->r = NULL;
    return temp;
}
TreeNode * insert_node(TreeNode * node, int key)
{
    if (node == NULL) return new_node(key);
    if (key < node->key)
        node->l = insert_node(node->l, key);
    else if (key > node->key)
        node->r = insert_node(node->r, key);
    return node;
}
void print_node(TreeNode *node){
     if(node) {
         printf("%d \n", node->key);
         print_node(node->l);
         print_node(node->r);
     }
 }
int main(){

     TreeNode *node=NULL;

    int input_size = 1000;
    int data_maxval = 10000;

    int *input = (int *)malloc(sizeof(int)*input_size);

    for (int i = 0; i < input_size; i++) {
        input[i] = random(data_maxval);
        node=insert_node(node,input[i]);
    }
    printf("sort: \n");
    print_node(node);
 }