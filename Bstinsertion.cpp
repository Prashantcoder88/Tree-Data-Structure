// Online C++ compiler to run C++ program online
#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    
};
struct node* createNode(int data){
    struct node* n; //createing a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memory in the heap
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root != NULL)
    {
        prev = root;
        if(key == root -> data)
        {
            cout<<"key already exits";
            return;
        }
        else if(key < root -> data)
        {
            root = root -> right;
        }
        else
        {
            root = root -> right;
        }
    }
    struct node* curr = createNode(key);
    if(key < prev -> data){
        prev -> left = curr;
    }
    else{
        prev -> right = curr;
    }
}
int main() {
   struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
   insert(p,14);
   cout<<p->right->right->data;
   

    return 0;
}