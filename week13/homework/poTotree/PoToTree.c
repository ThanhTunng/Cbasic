#include "abc.h"
#include <stdio.h>
#include <string.h>
#include "stackLL.h"
int isOperator(char c){
  if(c == '+' || c == '-' || c== '*' || c == '/' || c == '^'){
    return 2;
  }else{
    return 1;
  }
}
treeNode *changeToTree(char postfix[]){
  stackNode *stack;
  stack_init(&stack);
  
  treeNode *root;
  
  int n = strlen(postfix);
  
  for(int i=0; i<n; i++){
    if(isOperator(postfix[i]) == 1){
      root = makeNode(postfix[i]);
      push(root,&stack);
    }else{
      root = makeNode(postfix[i]);

      root->rightC = pop(&stack);
      root->leftC = pop(&stack);
      
      push(root,&stack);
    }
  }
    root = pop(&stack);

    return root;
}

void inOrder(treeNode *root){
  if(root==NULL) return;
  inOrder(root->leftC);
  printf("%c",root->data);
  inOrder(root->rightC);
  printf("\n");
  return;
}
int main(){
  
  treeNode *root = changeToTree("13+");
  inOrder(root);

  return 0;
}
      
  
